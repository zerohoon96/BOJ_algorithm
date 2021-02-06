#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int arr1[4]={-1,0,1,0};
int arr2[4]={0,-1,0,1};
int farm[52][52]; //좌표로 배주 위치 저장 
vector<pair<int,int> > info; //배추 위치 저장 

void DFS(int x,int y){
	int i;
	int n1,n2;
	for(i=0;i<4;i++){
		n1=x+arr1[i];
		n2=y+arr2[i];
		if(farm[n1][n2]==1){
			farm[n1][n2]=2;
			DFS(n1,n2);
		}
	}
} 
int main(void){
	int i,j,k; 
	int t,a,b,n;
	int x,y,tmp,ct=0;
	scanf("%d",&t);
	vector<int> res(t);
	
	for(i=0;i<t;i++){
		scanf("%d%d%d",&a,&b,&n);
		for(j=0;j<n;j++){
			scanf("%d%d",&x,&y);
			info.push_back(make_pair(x+1,y+1));
			farm[x+1][y+1]=1;
		}
		for(j=0;j<n;j++){
			x=info[j].first;
			y=info[j].second;
			
			//3 : 루트, 2 : 루트와 연결됨, 1 : 미확인(배추존재), 0 : 배추x 
			for(k=0;k<4;k++){
				tmp=farm[x+arr1[k]][y+arr2[k]];
				if(tmp==3||tmp==2){ //루트와 연결 돼있음 
					farm[x][y]=2;
					DFS(x,y);
					break;
				}
			}
			if(k==4){ //루트와 연결 안돼있음 -> 루트와 연결후 주변 연결 
				ct++;
				farm[x][y]=3;
				DFS(x,y);
			}
		}
		res[i]=ct;
		ct=0;
		info.clear();		
		memset(farm,0,sizeof(int)*52*52);
	}
	
	for(i=0;i<t;i++)
		printf("%d\n",res[i]);
	return 0;
}

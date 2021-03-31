#include <stdio.h>
#include <algorithm> 
#include <vector>
using namespace std;
bool cmp(const pair<int,int> &p1,const pair<int,int> &p2){
	if(p1.second!=p2.second) //등장횟수 순으로 정렬
		return p1.second<p2.second;
	else //숫자 크기 순으로 정렬
		return p1.first<p2.first;
}
int main(void){
	int i,j,r,c,k,cur,idx,_max,res=-1,sec=0,col=3,row=3,arr[100][100];
	scanf("%d%d%d",&r,&c,&k);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&arr[i][j]);
			
	while(1){
		if(arr[r-1][c-1]==k){ //종료 검사 
			res=sec;
			break;
		}
		if(sec==100) //100초가 됐는데 못찾았으면 종료 
			break;
		_max=0;
		if(row>=col){ //R 연산 
			for(i=0;i<row;i++){
				vector<pair<int,int> >check(100); //(숫자,등장횟수)를 저장하는 백터
				idx=100;
				cur=0;
				for(j=0;j<col;j++){
					if(arr[i][j]==0)
						continue;
					if(check[arr[i][j]-1].first==0) //아직 접근되지 않은 수 개수를 줄임 
						idx--; 
					check[arr[i][j]-1]=make_pair(arr[i][j],check[arr[i][j]-1].second+1); //쌓인 데이터에 누적 
					arr[i][j]=0;
				}
				sort(check.begin(),check.end(),cmp); //우선순위에 따라 정렬
				for(j=idx;j<100;j++){ //열에 새로운 데이터를 입력 
					if(cur==100)
						break;
					arr[i][cur]=check[j].first;
					arr[i][cur+1]=check[j].second;
					cur+=2;
				}
				if(cur>_max) //최대 열 검사 
					_max=cur; 
			}
			col=_max; //최대 열 업데이트 
		}
		else{ //C 연산 
			for(i=0;i<col;i++){
				vector<pair<int,int> >check(100); //(숫자,등장횟수)를 저장하는 백터
				idx=100;
				cur=0;
				for(j=0;j<row;j++){
					if(arr[j][i]==0)
						continue;
					if(check[arr[j][i]-1].first==0) //아직 접근되지 않은 수 개수를 줄임 
						idx--; 
					check[arr[j][i]-1]=make_pair(arr[j][i],check[arr[j][i]-1].second+1); //쌓인 데이터에 누적
					arr[j][i]=0;
				}
				sort(check.begin(),check.end(),cmp); //우선순위에 따라 정렬
				for(j=idx;j<100;j++){ //행에 새로운 데이터를 입력 
					if(cur==100)
						break;
					arr[cur][i]=check[j].first;
					arr[cur+1][i]=check[j].second;
					cur+=2;
				}
				if(cur>_max) //최대 열 검사 
					_max=cur; 
			}
			row=_max; //최대 행 업데이트 
		}
		sec++;
	}
	printf("%d\n",res);
	return 0;
}

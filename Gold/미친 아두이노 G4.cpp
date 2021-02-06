#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int r,c,i,j,k,x,y,tmp,tail=0,cur_x,cur_y,mini,index=0;
	bool flag=true;
	char ch,way[100];
	vector<pair<int,int> > move(10);
	vector<pair<int,int> > Rpos;
	move[1]=make_pair(1,-1);
	move[2]=make_pair(1,0);
	move[3]=make_pair(1,1);
	move[4]=make_pair(0,-1);
	move[5]=make_pair(0,0);
	move[6]=make_pair(0,1);
	move[7]=make_pair(-1,-1);
	move[8]=make_pair(-1,0);
	move[9]=make_pair(-1,1);
	
	scanf("%d%d",&r,&c);
	scanf("%c",&ch);
	vector<vector<int> >arr(r,vector<int>(c));
	for(i=0;i<r;i++){ //현재 게임 정보를 입력받음 
		for(j=0;j<c;j++){
			scanf("%c",&ch);
			if(ch=='I'){
				cur_x=i;
				cur_y=j;
				arr[i][j]=2;
			}
			else if(ch=='R'){
				Rpos.push_back(make_pair(i,j));
				tail++;
				arr[i][j]=1;
			}
		}
		scanf("%c",&ch);
	}
	scanf("%s",way);
	for(i=0;i<strlen(way);i++){ //한단계씩 진행 
		tmp=way[i]-48;
		cur_x+=move[tmp].first;
		cur_y+=move[tmp].second;
		if(arr[cur_x][cur_y]==1){ //이동하려는 위치가 미친 아두이노 
			flag=false;
			break;
		}
		arr=vector<vector<int> >(r,vector<int>(c)); //배열 초기화 
		arr[cur_x][cur_y]=2; //위치 저장
	 
		for(j=0;j<tail;j++){ //R위치 업데이트. 도중에 I 위치와 같아지면 끝
			x=Rpos[j].first;
			y=Rpos[j].second;
			mini=2147000000;
			for(k=1;k<10;k++){ //최적 이동위치 find 
				tmp=abs(x+move[k].first-cur_x)+abs(y+move[k].second-cur_y);
				if(tmp<mini){
					mini=tmp;
					index=k;
				}
			}
			x+=move[index].first;
			y+=move[index].second;
			if(mini==0){ //미친 아두이노가 새롭게 이동한 위치가 겹치는 경우 
				flag=false;
				break;
			}
			
			Rpos[j]=make_pair(x,y); //새로운 위치 업데이트 
			arr[x][y]++;
		}
		if(!flag)
			break;
		sort(Rpos.begin(),Rpos.end());
		for(j=0;j<tail;j++){ //미친 아두이노의 위치 중복 검사 
			x=Rpos[j].first;
			y=Rpos[j].second;
			if(arr[x][y]>1){
				for(k=0;k<arr[x][y];k++)
					Rpos.erase(Rpos.begin()+j);
				tail-=arr[x][y];
				arr[x][y]=0;
				j--;
			} 
		} 
	}
	
	if(!flag)
		printf("kraj %d\n",i+1);
	else{ 
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(arr[i][j]==0)
					printf(".");
				else if(arr[i][j]==1)
					printf("R");
				else
					printf("I");
			}
			puts("");
		}
	}
	return 0;
}

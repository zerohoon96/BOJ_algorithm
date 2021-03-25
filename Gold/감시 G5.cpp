#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
struct cam_info{ //카메라 정보를 저장하는 구조체 
	int num,x,y;
	cam_info(int a,int b,int c){
		num=a;
		x=b;
		y=c;
	}
};
int n,m,map[8][8],res=0,emp=0;
int info_1[5][4][4]={ //카메라별 감시방향 저장(1~5번순, 방향은 북->서->남->동 순) 
	{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}},
	{{1,0,1,0},{0,1,0,1}},
	{{1,1,0,0},{0,1,1,0},{1,0,0,1},{0,0,1,1}},
	
	{{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}},
	{{1,1,1,1}}
};
int info_2[5]={4,2,4,4,1}; //카메라별 감시방향 경우의 수 저장 
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}}; //북,서,남,동 방향 저장 
vector<cam_info> arr;
void DFS(int ct){
	int i,j,k,cam,x,y,tmp_x,tmp_y,tmp_empty,tmp[8][8];
	if(ct==(int)arr.size()){ //모든 카메라를 세팅했을때 최솟값 업데이트
		if(emp<res)
			res=emp;
		return; 
	}
	//최초 map 배열 정보 저장
	for(i=0;i<n;i++) 
		for(j=0;j<m;j++)
			tmp[i][j]=map[i][j];
	//현재 단계의 카메라 정보, 감시 가능 개수 저장
	cam=arr[ct].num;
	x=arr[ct].x;
	y=arr[ct].y;
	tmp_empty=emp;
	for(i=0;i<info_2[cam];i++){ //현재 단계 카메라의 모든 감시 경우를 탐색
		for(j=0;j<4;j++){ //현재 감시 경우에서 정보 업데이트
			if(info_1[cam][i][j]==0)
				continue;
			tmp_x=dir[j][0]; //현재 감시 방향 정보 저장
			tmp_y=dir[j][1];
			if(tmp_y==0){ //x 방향으로 나아가는 경우 
				while(1){
					if(x+tmp_x<0||x+tmp_x>=n) //범위를 벗어나면 break 
						break;
					if(map[x+tmp_x][y]==6) //벽을 만나면 break 
						break;
					if(map[x+tmp_x][y]==0){ //감시 가능하면 감시 
						map[x+tmp_x][y]=1; 
						emp--;
					}
					if(tmp_x>0) //x값 업데이트 
						tmp_x++;
					else
						tmp_x--;
				}
			}
			else if(tmp_x==0){ //y 방향으로 나아가는 경우 
				while(1){
					if(y+tmp_y<0||y+tmp_y>=m) //범위를 벗어나면 break 
						break;
					if(map[x][y+tmp_y]==6) //벽을 만나면 break 
						break;
					if(map[x][y+tmp_y]==0){ //감시 가능하면 감시 
						map[x][y+tmp_y]=1; 
						emp--;
					}
					if(tmp_y>0) //y값 업데이트 
						tmp_y++;
					else
						tmp_y--;
				}
			}
		}
		DFS(ct+1); //다음 단계 실행 
		//실행전으로 정보 복구
		emp=tmp_empty;
		for(j=0;j<n;j++) 
			for(k=0;k<m;k++)
				map[j][k]=tmp[j][k];
	}
}
int main(void){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==0){ //감시 가능 영역 개수 저장 
				res++;
				emp++;
			}
			else if(map[i][j]<6){ //카메라들의 리스트를 저장 
				arr.push_back(cam_info(map[i][j]-1,i,j));
			}
		}
	}
	DFS(0);
	printf("%d\n",res);
	return 0;
}

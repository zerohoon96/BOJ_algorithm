#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
struct cam_info{ //ī�޶� ������ �����ϴ� ����ü 
	int num,x,y;
	cam_info(int a,int b,int c){
		num=a;
		x=b;
		y=c;
	}
};
int n,m,map[8][8],res=0,emp=0;
int info_1[5][4][4]={ //ī�޶� ���ù��� ����(1~5����, ������ ��->��->��->�� ��) 
	{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}},
	{{1,0,1,0},{0,1,0,1}},
	{{1,1,0,0},{0,1,1,0},{1,0,0,1},{0,0,1,1}},
	
	{{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}},
	{{1,1,1,1}}
};
int info_2[5]={4,2,4,4,1}; //ī�޶� ���ù��� ����� �� ���� 
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}}; //��,��,��,�� ���� ���� 
vector<cam_info> arr;
void DFS(int ct){
	int i,j,k,cam,x,y,tmp_x,tmp_y,tmp_empty,tmp[8][8];
	if(ct==(int)arr.size()){ //��� ī�޶� ���������� �ּڰ� ������Ʈ
		if(emp<res)
			res=emp;
		return; 
	}
	//���� map �迭 ���� ����
	for(i=0;i<n;i++) 
		for(j=0;j<m;j++)
			tmp[i][j]=map[i][j];
	//���� �ܰ��� ī�޶� ����, ���� ���� ���� ����
	cam=arr[ct].num;
	x=arr[ct].x;
	y=arr[ct].y;
	tmp_empty=emp;
	for(i=0;i<info_2[cam];i++){ //���� �ܰ� ī�޶��� ��� ���� ��츦 Ž��
		for(j=0;j<4;j++){ //���� ���� ��쿡�� ���� ������Ʈ
			if(info_1[cam][i][j]==0)
				continue;
			tmp_x=dir[j][0]; //���� ���� ���� ���� ����
			tmp_y=dir[j][1];
			if(tmp_y==0){ //x �������� ���ư��� ��� 
				while(1){
					if(x+tmp_x<0||x+tmp_x>=n) //������ ����� break 
						break;
					if(map[x+tmp_x][y]==6) //���� ������ break 
						break;
					if(map[x+tmp_x][y]==0){ //���� �����ϸ� ���� 
						map[x+tmp_x][y]=1; 
						emp--;
					}
					if(tmp_x>0) //x�� ������Ʈ 
						tmp_x++;
					else
						tmp_x--;
				}
			}
			else if(tmp_x==0){ //y �������� ���ư��� ��� 
				while(1){
					if(y+tmp_y<0||y+tmp_y>=m) //������ ����� break 
						break;
					if(map[x][y+tmp_y]==6) //���� ������ break 
						break;
					if(map[x][y+tmp_y]==0){ //���� �����ϸ� ���� 
						map[x][y+tmp_y]=1; 
						emp--;
					}
					if(tmp_y>0) //y�� ������Ʈ 
						tmp_y++;
					else
						tmp_y--;
				}
			}
		}
		DFS(ct+1); //���� �ܰ� ���� 
		//���������� ���� ����
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
			if(map[i][j]==0){ //���� ���� ���� ���� ���� 
				res++;
				emp++;
			}
			else if(map[i][j]<6){ //ī�޶���� ����Ʈ�� ���� 
				arr.push_back(cam_info(map[i][j]-1,i,j));
			}
		}
	}
	DFS(0);
	printf("%d\n",res);
	return 0;
}

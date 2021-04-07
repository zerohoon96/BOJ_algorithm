#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int main(void){
	int i,j,n,m,x,y,order,tmp,tmp_x,tmp_y;
	int rotate[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
	int dice[4][6]={{3,1,0,5,4,2},{2,1,5,0,4,3},{1,5,2,3,0,4},{4,0,2,3,5,1}};
	int tmp_cur[6],cur[6]={0,0,0,0,0,0};
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&order);
	vector<vector<int> >map(n,vector<int>(m));
	vector<int> res(order);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&map[i][j]);

	for(i=0;i<order;i++){
		scanf("%d",&tmp);
		tmp_x=x+rotate[tmp-1][0];
		tmp_y=y+rotate[tmp-1][1];
		
		//������ ������� �˻� 
		if(tmp_x<0||tmp_x>n-1||tmp_y<0||tmp_y>m-1){
			res[i]=-1;
			continue;
		}
		//ĭ �̵� 
		x=tmp_x;
		y=tmp_y;
		
		//�ֻ��� ������Ʈ
		for(j=0;j<6;j++)
			tmp_cur[dice[tmp-1][j]]=cur[j];
		memcpy(cur,tmp_cur,sizeof(int)*6);
		
		if(map[x][y]==0){ //�̵��� map �ڸ��� 0�� ��� 
			map[x][y]=cur[5]; 
		}
		else{ //�̵��� map �ڸ��� 0�� �ƴ� ��� 
			cur[5]=map[x][y];
			map[x][y]=0;
		}
		res[i]=cur[0];
	}
	
	for(i=0;i<order;i++){ //����� ������ ����� ��� 
		if(res[i]!=-1)
			printf("%d\n",res[i]);
	}
	return 0;
}

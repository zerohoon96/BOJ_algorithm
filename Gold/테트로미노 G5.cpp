#include <stdio.h>
int n,m,res=0,map[500][500],check[500][500],tmp[3][2];
int rotate[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void DFS(int x,int y,int ct,int sum){
	int i,j,tmp_x,tmp_y;
	sum+=map[x][y];
	if(ct+1==4){ //4���� ���� ���� ��� ���� �˻� 
		if(sum>res)
			res=sum;
		return;
	}
	tmp[ct][0]=x;
	tmp[ct][1]=y;
	check[x][y]=1;
	for(i=0;i<=ct;i++){ //������� Ž���� ������ ��� Ž�� 
		tmp_x=tmp[i][0];
		tmp_y=tmp[i][1];
		for(j=0;j<4;j++){ //������ �ٲ㰡�� ���� ���� 
			if(tmp_x+rotate[j][0]<0||tmp_x+rotate[j][0]>n-1||tmp_y+rotate[j][1]<0||tmp_y+rotate[j][1]>m-1) //������ ��� ��� continue
				continue;
			if(check[tmp_x+rotate[j][0]][tmp_y+rotate[j][1]]==1) //�̹� ������ ��� continue 
				continue;
			DFS(tmp_x+rotate[j][0],tmp_y+rotate[j][1],ct+1,sum);
		}
	}
	tmp[ct][0]=0;
	tmp[ct][1]=0;
	check[x][y]=0;
}
int main(void){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	for(i=0;i<n;i++) //��� ��忡 ���ؼ� Ž�� 
		for(j=0;j<m;j++)
			DFS(i,j,0,0);
	printf("%d\n",res);
	return 0;
}

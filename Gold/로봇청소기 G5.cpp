#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int i,j,n,m,r,c,dir,ct=0;
	int tmp_r,tmp_c,tmp_dir;
	int info[4][2]={{-1,0},{0,1},{1,0},{0,-1}}; //��,��,��,�� ������ ���� ���� 
	scanf("%d%d",&n,&m);
	vector<vector<int> >map(n+2,vector<int>(m+2,1));
	scanf("%d%d%d",&r,&c,&dir);
	r++;
	c++;
	for(i=1;i<=n;i++) //��� ���� �Է� 
		for(j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	while(1){
		if(map[r][c]==0){ //û�ҵǾ� ���� ������ û�� (2�� ǥ��) 
			map[r][c]=2;
			ct++;
		}
		tmp_dir=dir;
		for(i=0;i<4;i++){ //������ �ٲٸ� �˻� 
			tmp_dir--; //�������� ���� ������Ʈ 
			if(tmp_dir<0)
				tmp_dir=3;
			tmp_r=r+info[tmp_dir][0];
			tmp_c=c+info[tmp_dir][1];
			if(map[tmp_r][tmp_c]==0){ //���� ���⿡�� ��ĭ ���������� û�� �ȵ� ĭ �߰��� ��� ����
				r=tmp_r;
				c=tmp_c;
				dir=tmp_dir;
				break;
			}
		}
		if(i<4) //���� ĭ���� ���� 
			continue;
		else{ //���� �Ұ���->���� �õ� 
			r-=info[dir][0];
			c-=info[dir][1];
			if(map[r][c]==1) //������ �Ұ����ϸ� �۵� ���� 
				break;
		}
	}
	printf("%d\n",ct); //�� ��� 
	return 0;
}

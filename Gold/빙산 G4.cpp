#include <stdio.h>
#include <vector>
using namespace std;
struct info{
	int x,y,val;
	info(int a,int b,int c){
		x=a;
		y=b;
		val=c;
	}
};
int n,m,ct,map[300][300],check[300][300];
int rotate[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
vector<info>sea;
void ice(int x,int y){
	int i,j,tmp_x,tmp_y,emp=0;
	check[x][y]=1;
	ct++;
	for(i=0;i<4;i++){ //���� 4���� Ž��
		tmp_x=x+rotate[i][0];
		tmp_y=y+rotate[i][1];
		if(tmp_x<0||tmp_x>n-1||tmp_y<0||tmp_y>m-1) //������ ��� 
			continue;
		if(map[tmp_x][tmp_y]<1){ //������ ���� ������ ��� 
			emp++;
			continue;
		}
		if(check[tmp_x][tmp_y]!=0) //�̹� �湮�� ��� 
			continue;
		ice(tmp_x,tmp_y); //���ȣ�� 
	}
	sea.push_back(info(x,y,emp)); //��ǥ, �� ���� ����ü�� ���� 
}
int main(void){
	int i,j,x,y,res=0,mt=0;
	bool flag;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]>0){ //���� �� ������ ���� 
				mt++;
				if(sea.empty())
					sea.push_back(info(i,j,1));
			}
		}
	}
	while(1){
		if(mt<=1){ //���̻� 2���� �ɰ� �� ���� (���ų�, 1�� ���� ���) 
			res=0;
			break;
		}
		for(i=0;i<(int)sea.size();i++) //ù ���� ��ġ ����
			if(map[sea[i].x][sea[i].y]>0)
				break;
		x=sea[i].x;
		y=sea[i].y;
		sea.clear();
		ct=0;
		ice(x,y);
		if(ct<mt) //����� �ΰ� �̻��� ��� ���� (�������� ���������� Ž���ߴµ� ���� Ž������ ����) 
			break;
		for(i=0;i<(int)sea.size();i++){ //����� ������ �������� ���� ���� 
			x=sea[i].x;
			y=sea[i].y;
			map[x][y]-=sea[i].val;
			if(map[x][y]<1)
				mt--; 
			check[x][y]=0; //üũ�迭 ���� 
		}
		res++; //1�� ����
	}
	printf("%d\n",res);
	return 0;
}

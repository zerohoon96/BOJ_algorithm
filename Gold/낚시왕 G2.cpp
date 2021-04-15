#include <stdio.h>
#include <vector>
using namespace std;
struct shark{ //��� ������ �����ϴ� ����ü 
	int s,d,z;
	shark(){}
	shark(int a,int b,int c){
		s=a;
		d=b;
		z=c;
	}
};
int main(void){
	int i,j,r,c,n,x,y,s,d,z,diff,cur=0,res=0;
	int n1,n2,n3,n4,n5;
	int rotate[5][2]={{},{-1,0},{1,0},{0,1},{0,-1}}; 
	scanf("%d%d%d",&r,&c,&n);
	vector<vector<shark> > map(r,vector<shark>(c));
	vector<pair<int,int> > info;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			map[i][j]=shark(0,0,0);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5);
		map[n1-1][n2-1]=shark(n3,n4,n5);
		info.push_back(make_pair(n1-1,n2-1));
	}
	while(cur<c){ //���� ���������� �̵��� ������ �ݺ�
		vector<vector<shark> > tmp_map(r,vector<shark>(c));
		vector<pair<int,int> > tmp_info;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				tmp_map[i][j]=shark(0,0,0);
				
		for(i=0;i<r;i++){ //���ò��� ��� ��� Ž�� 
			if(map[i][cur].z>0){
				res+=map[i][cur].z;
				map[i][cur].z=0;
				break;
			}
		}
		
		for(i=0;i<(int)info.size();i++){ //���� ������ ��ġ�� �̵� 
			x=info[i].first;
			y=info[i].second;
			if(map[x][y].z<=0) //��ȿ���� ���� ���� ���� ���� (�̹� ���� ���)  
				continue;
			s=map[x][y].s;
			d=map[x][y].d;
			z=map[x][y].z;
			x+=rotate[d][0]*s; //���� ����� �ӵ��� ���� ���ο� ��ġ�� ���� 
			y+=rotate[d][1]*s;
			if(x<0||x>r-1){ //x�� ������ �Ѿ ��� 
				if(x<0){ //�Ѿ ������ ��� 
					diff=x*-1;
					d=2;
				}
				else{
					diff=x-(r-1);
					d=1;
				}
				if(diff/(r-1)>0){ //�Ѿ ������ ���� ����, ���ο� ��ġ ���� 
					if(diff/(r-1)%2==1){
						if(d==1)
							d=2;
						else
							d=1;
					}
					diff%=r-1;
				}
				if(d==1)
					x=r-1-diff;
				else
					x=diff;
			}
			if(y<0||y>c-1){ //y�� ������ �Ѿ ��� 
				if(y<0){ //�Ѿ ������ ��� 
					diff=y*-1;
					d=3;
				}
				else{
					diff=y-(c-1);
					d=4;
				}
				if(diff/(c-1)>0){ //�Ѿ ������ ���� ����, ���ο� ��ġ ���� 
					if(diff/(c-1)%2==1){
						if(d==3)
							d=4;
						else
							d=3;
					}
					diff%=c-1;
				}
				if(d==4)
					y=c-1-diff;
				else
					y=diff;
			}
			if(tmp_map[x][y].z<=0){ //�ƹ��� ���� ��� ���� ���� ���� 
				tmp_info.push_back(make_pair(x,y));
				tmp_map[x][y]=shark(s,d,z);
			}
			else if(tmp_map[x][y].z<z){ //�̵��Ϸ��� ĭ�� ũ�Ⱑ ���� �� �ִ� ��� ����
				tmp_map[x][y]=shark(s,d,z);
			}
			else //�̵��Ϸ��� ĭ�� ũ�Ⱑ ū �� �ִ� ��� ���� 
				continue;
		} 
		map=tmp_map; //�ӽ� ���� ����� 
		info=tmp_info;
		cur++; //���ò� ��ġ �̵�
	}
	printf("%d\n",res); //���� ��� 
	return 0;
}

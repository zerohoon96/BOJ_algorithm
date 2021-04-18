#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
struct info_1{ //ĭ�� �������� ���̾�� ������ �����ϴ� ����ü
	int m,s,d,ct;
	info_1(){}
	info_1(int n1,int n2,int n3,int n4){
		m=n1;
		s=n2;
		d=n3;
		ct=n4;
	}
};
struct info_2{ //���̾ ������ ������ �����ϴ� ����ü 
	int r,c,m,d,s;
	info_2(int n1,int n2,int n3,int n4,int n5){
		r=n1;
		c=n2;
		m=n3;
		s=n4;
		d=n5;
	}
};
int main(void){
	int i,j,a,res=0;
	int n,M,k,r,c,m,d,s,ct;
	int rotate[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
	scanf("%d%d%d",&n,&M,&k);
	vector<info_2>fireball;
	for(i=0;i<M;i++){
		scanf("%d%d%d%d%d",&r,&c,&m,&s,&d);
		fireball.push_back(info_2(r,c,m,s,d));
	}
	for(i=0;i<k;i++){ //k�� �̵��ϸ� ���� 
		vector<vector<info_1> >map(n+1,vector<info_1>(n+1)); 
		vector<pair<int,int> >store_res; 
		for(j=1;j<=n;j++)
			for(a=1;a<=n;a++)
				map[j][a]=info_1(0,0,0,0);

		for(j=0;j<(int)fireball.size();j++){ //��� ���̾�� �̵� ������ map�� ������Ŵ
			r=fireball[j].r;
			c=fireball[j].c;
			m=fireball[j].m;
			s=fireball[j].s;
			d=fireball[j].d;
			
			//���̾�� ���⿡ ���� �̵�
			r+=rotate[d][0]*s; 
			c+=rotate[d][1]*s;
			if(r<=0)
				r=n-(abs(r)%n);
			if(r>n){
				if(r%n==0)
					r=n;
				else
					r%=n;
			}
			if(c<=0)
				c=n-(abs(c)%n);
			if(c>n){
				if(c%n==0)
					c=n;
				else
					c%=n;
			}
			
			if(map[r][c].ct==0) //���̾�� �ִ� ĭ�� ������ ����(�ѹ���) 
				store_res.push_back(make_pair(r,c));
			map[r][c].m+=m;
			map[r][c].s+=s;
			if(map[r][c].ct==0) //ù ������ ��� ������ �״�� ���� 
				map[r][c].d=d;
			else{ //ù ������ �ƴ� ��� Ȧ/¦ �Ǵ��ϸ� ���� (��� Ȧ�̸� ���� Ƚ���� ����, ��� ¦�̸� 0�� �ǵ���) 
				if(map[r][c].ct==1){ //�� ��° ������ ��� �̹� ����� �������� Ȧ/¦ ���θ� �Ǵ� 
					if(map[r][c].d%2==0)
						map[r][c].d=0;
					else
						map[r][c].d=1;
				}
				if(d%2==1) //Ȧ�� �����̸� 1 ���� (���߿� ��ģ ������ ��� Ȧ�� or ��� ¦������ �Ǻ�) 
					map[r][c].d+=1;
			}
			map[r][c].ct++;
		}
		
		fireball.clear();
		for(j=0;j<(int)store_res.size();j++){ //�̵��� ���̾�� ���� ����� �������� ���ο� ���̾ ����Ʈ ����
			r=store_res[j].first;
			c=store_res[j].second;
			m=map[r][c].m;
			s=map[r][c].s;
			d=map[r][c].d;
			ct=map[r][c].ct;
			if(ct>1){ //2�� �̻� ���̾�� ������ ��� 
				m/=5;
				if(m<=0)
					continue;
				s/=ct;
				if(d==ct||d==0) //������ ���� ��� Ȧ���̰ų� ��� ¦�� 
					d=0;
				else
					d=1;
				for(a=0;a<4;a++){
					fireball.push_back(info_2(r,c,m,s,d));
					d+=2;
				}
			}
			else //�� ���� ���̾�� ������ ��� 
				fireball.push_back(info_2(r,c,m,s,d));
		}
	}
	for(i=0;i<(int)fireball.size();i++)
		res+=fireball[i].m;
	printf("%d\n",res);
	return 0;
}

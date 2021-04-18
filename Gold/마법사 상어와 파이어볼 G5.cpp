#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
struct info_1{ //칸에 합쳐지는 파이어볼의 정보를 저장하는 구조체
	int m,s,d,ct;
	info_1(){}
	info_1(int n1,int n2,int n3,int n4){
		m=n1;
		s=n2;
		d=n3;
		ct=n4;
	}
};
struct info_2{ //파이어볼 각각의 정보를 저장하는 구조체 
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
	for(i=0;i<k;i++){ //k번 이동하며 진행 
		vector<vector<info_1> >map(n+1,vector<info_1>(n+1)); 
		vector<pair<int,int> >store_res; 
		for(j=1;j<=n;j++)
			for(a=1;a<=n;a++)
				map[j][a]=info_1(0,0,0,0);

		for(j=0;j<(int)fireball.size();j++){ //모든 파이어볼의 이동 정보를 map에 누적시킴
			r=fireball[j].r;
			c=fireball[j].c;
			m=fireball[j].m;
			s=fireball[j].s;
			d=fireball[j].d;
			
			//파이어볼의 방향에 따라 이동
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
			
			if(map[r][c].ct==0) //파이어볼이 있는 칸의 정보를 저장(한번만) 
				store_res.push_back(make_pair(r,c));
			map[r][c].m+=m;
			map[r][c].s+=s;
			if(map[r][c].ct==0) //첫 누적인 경우 방향을 그대로 저장 
				map[r][c].d=d;
			else{ //첫 누적이 아닌 경우 홀/짝 판단하며 누적 (모두 홀이면 누적 횟수와 같고, 모두 짝이면 0이 되도록) 
				if(map[r][c].ct==1){ //두 번째 누적인 경우 이미 저장된 데이터의 홀/짝 여부를 판단 
					if(map[r][c].d%2==0)
						map[r][c].d=0;
					else
						map[r][c].d=1;
				}
				if(d%2==1) //홀수 방향이면 1 누적 (나중에 합친 방향이 모두 홀수 or 모두 짝수인지 판별) 
					map[r][c].d+=1;
			}
			map[r][c].ct++;
		}
		
		fireball.clear();
		for(j=0;j<(int)store_res.size();j++){ //이동한 파이어볼의 누적 결과를 바탕으로 새로운 파이어볼 리스트 생성
			r=store_res[j].first;
			c=store_res[j].second;
			m=map[r][c].m;
			s=map[r][c].s;
			d=map[r][c].d;
			ct=map[r][c].ct;
			if(ct>1){ //2개 이상 파이어볼이 합쳐진 경우 
				m/=5;
				if(m<=0)
					continue;
				s/=ct;
				if(d==ct||d==0) //방향의 합이 모두 홀수이거나 모두 짝수 
					d=0;
				else
					d=1;
				for(a=0;a<4;a++){
					fireball.push_back(info_2(r,c,m,s,d));
					d+=2;
				}
			}
			else //한 개의 파이어볼만 합쳐진 경우 
				fireball.push_back(info_2(r,c,m,s,d));
		}
	}
	for(i=0;i<(int)fireball.size();i++)
		res+=fireball[i].m;
	printf("%d\n",res);
	return 0;
}

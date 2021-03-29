#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct fish{ //�ĺ� ����� ������ �����ϴ� ����ü 
	int x,y,val;
	fish(int a,int b,int c){
		x=a;
		y=b;
		val=c;
	}	
};
bool cmp(const fish& a,const fish& b){ //fish ����ü�� ���� ���� 
	if(a.x==b.x) //x�� ������ ���� �� 
		return a.y<b.y;
	else //���� �� 
		return a.x<b.x;
}
int main(void){
	int n,i,j,k,x,y,mini,shark=2,ct=0,res=0;
	int tmp_x,tmp_y,tmp_val;
	int rotate[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; 
	scanf("%d",&n);
	vector<vector<int> >map(n,vector<int>(n));
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&map[i][j]); 
			if(map[i][j]==9){ //�Ʊ����� ��ġ ���� 
				x=i;
				y=j;
			}
		}
	} 
	while(1){  
		queue<fish> que;
		vector<vector<int> > check(n,vector<int>(n));
		vector<fish> data;
		mini=n*n;
		que.push(fish(x,y,0));
		check[x][y]=1;
		while(!que.empty()){ //BFS 
			tmp_x=que.front().x;
			tmp_y=que.front().y;
			tmp_val=que.front().val;
			que.pop();
			if(tmp_val>mini) //�� ª�� �Ÿ����� �̹� �ٸ� ����⸦ ã�� 
				continue;
			if(map[tmp_x][tmp_y]<9&&map[tmp_x][tmp_y]>0&&map[tmp_x][tmp_y]<shark){ //fish ���Ϳ� �߰�(�ĺ���)
				data.push_back(fish(tmp_x,tmp_y,tmp_val));
				mini=tmp_val;
				continue;
			}
			if(!data.empty()) //�ش� ĭ�� ����Ⱑ ���µ� �̹� ���Ϳ� ����Ⱑ ���� 
				continue;
			for(k=0;k<4;k++){ //4���� ���� queue�� push 
				i=tmp_x+rotate[k][0];
				j=tmp_y+rotate[k][1];
				if(i<0||i>n-1||j<0||j>n-1) //������ ��� 
					continue;
				if(check[i][j]==1) //�̹� ������ �ڸ� 
					continue;
				if(map[i][j]>shark) //���纸�� ū ���
					continue;
				check[i][j]=1;
				que.push(fish(i,j,tmp_val+1)); //queue�� push 
			}
		}
		if(data.empty()) //���� �� �ִ� ����� �� �̻� x 
			break;
		sort(data.begin(),data.end(),cmp); //�켱������ ���� ���� (���� �Ÿ� ���͵��� ������) 
		res+=data.front().val; //��� ������Ʈ
		map[x][y]=0;
		x=data.front().x; //�Ʊ����� ��ġ ������Ʈ 
		y=data.front().y;
		map[x][y]=9;
		ct++;
		if(ct==shark){ //�Ʊ��� ũ�� ������Ʈ 
			ct=0;
			shark++; 
		}		 
	}
	printf("%d\n",res); 
	return 0;
}

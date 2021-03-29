#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct fish{ //후보 물고기 정보를 저장하는 구조체 
	int x,y,val;
	fish(int a,int b,int c){
		x=a;
		y=b;
		val=c;
	}	
};
bool cmp(const fish& a,const fish& b){ //fish 구조체의 정렬 기준 
	if(a.x==b.x) //x도 같으면 왼쪽 비교 
		return a.y<b.y;
	else //위쪽 비교 
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
			if(map[i][j]==9){ //아기상어의 위치 저장 
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
			if(tmp_val>mini) //더 짧은 거리에서 이미 다른 물고기를 찾음 
				continue;
			if(map[tmp_x][tmp_y]<9&&map[tmp_x][tmp_y]>0&&map[tmp_x][tmp_y]<shark){ //fish 백터에 추가(후보군)
				data.push_back(fish(tmp_x,tmp_y,tmp_val));
				mini=tmp_val;
				continue;
			}
			if(!data.empty()) //해당 칸에 물고기가 없는데 이미 백터에 물고기가 있음 
				continue;
			for(k=0;k<4;k++){ //4방향 돌며 queue에 push 
				i=tmp_x+rotate[k][0];
				j=tmp_y+rotate[k][1];
				if(i<0||i>n-1||j<0||j>n-1) //범위를 벗어남 
					continue;
				if(check[i][j]==1) //이미 지나간 자리 
					continue;
				if(map[i][j]>shark) //현재보다 큰 상어
					continue;
				check[i][j]=1;
				que.push(fish(i,j,tmp_val+1)); //queue에 push 
			}
		}
		if(data.empty()) //먹을 수 있는 물고기 더 이상 x 
			break;
		sort(data.begin(),data.end(),cmp); //우선순위에 따라 정렬 (동일 거리 백터들이 모여있음) 
		res+=data.front().val; //결과 업데이트
		map[x][y]=0;
		x=data.front().x; //아기상어의 위치 업데이트 
		y=data.front().y;
		map[x][y]=9;
		ct++;
		if(ct==shark){ //아기상어 크기 업데이트 
			ct=0;
			shark++; 
		}		 
	}
	printf("%d\n",res); 
	return 0;
}

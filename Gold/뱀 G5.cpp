#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int main(void){
	int i,j,n,apple,r,c,m,s,x,y,cur=1,res=0,idx=0;
	int info[4][2]={{-1,0},{0,1},{1,0},{0,-1}}; //북->동->남->서 방향 정보 저장 
	char d;
	queue<pair<int,int> >que;
	scanf("%d",&n);
	vector<vector<int> >map(n,vector<int>(n));
	scanf("%d",&apple);
	for(i=0;i<apple;i++){ //사과 위치 정보 입력 
		scanf("%d%d",&r,&c);
		map[r-1][c-1]=1;
	}
	scanf("%d",&m);
	vector<pair<int,char> >rotate(m);
	for(i=0;i<m;i++){ //방향 전환 정보 입력 
		scanf("%d %c",&s,&d);
		getchar();
		rotate[i]=make_pair(s,d);
	}
	//최초 상태 정보 저장 
	i=j=0;
	map[0][0]=2;
	que.push(make_pair(0,0));
	while(1){
		//한칸 이동
		res++;
		i+=info[cur][0];
		j+=info[cur][1];
		if(i<0||i>n-1||j<0||j>n-1) //벽에 부딪힌 경우 종료 
			break;
		if(map[i][j]==2) //자신의 몸에 부딪힌 경우 종료 
			break;
		if(map[i][j]==0){ //새로운 칸에 사과가 없었으면 꼬리칸을 제거 
			x=que.front().first;
			y=que.front().second;
			que.pop();
			map[x][y]=0;
		}
		//새로운 칸 업데이트 
		que.push(make_pair(i,j)); 
		map[i][j]=2;
		if(res==rotate[idx].first){ //방향전환하는 경우 
			if(rotate[idx].second=='L'){ //왼쪽으로 회전 
				cur--;
				if(cur<0)
					cur=3;
			}
			if(rotate[idx].second=='D'){ //오른쪽으로 회전 
				cur++;
				if(cur>3)
					cur=0;
			}
			idx++;
		}
	}
	printf("%d\n",res);
	return 0;
}

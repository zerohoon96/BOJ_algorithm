#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main(void){
	int n,i,n1,n2,ct=0,start,end;
	priority_queue<pair<int,int> > que;
	vector<pair<int,int> > seat;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&n1,&n2);
		que.push(make_pair(n1*-1,n2)); //최소 힙에 저장 
	}
	
	while(!que.empty()){ //모든 사용자 반복 
		start=que.top().first*-1;
		end=que.top().second;	
		que.pop();
		for(i=0;i<seat.size();i++){ //모든자리 탐색
			if(start>=seat[i].first){ //이용가능 자리 찾음 
				seat[i].first=end;
				seat[i].second++;
				break;
			}
		}	
		if(i==seat.size()){ //이용 가능한 자리 못찾음 
			seat.push_back(make_pair(end,1));
		}
	}
	printf("%d\n",seat.size());
	for(i=0;i<seat.size();i++)
		printf("%d ",seat[i].second);
	return 0;
}

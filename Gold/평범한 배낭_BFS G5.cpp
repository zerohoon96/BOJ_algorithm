#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct bag{ //현재무게, 현재가치, 현재단계를 저장 
	int weigh,value,level;
	bag(int a,int b,int c){
		weigh=a;
		value=b;
		level=c;
	}
};
int main(void){
	queue<bag> que;
	int n,k,i,n1,n2,res=0,we,val,lev,cur_weigh,cur_value;
	scanf("%d%d",&n,&k);
	vector<pair<int,int> > arr(n);
	vector<int> dp(k+1);
	for(i=0;i<n;i++){ //데이터를 백터로 저장 
		scanf("%d%d",&n1,&n2);
		arr[i]=make_pair(n1,n2);
	}
	sort(arr.begin(),arr.end()); //작은 무게부터 시행 
	que.push(bag(0,0,0));
	while(!que.empty()){
		//현재 무게, 가치, 레벨 저장 
		we=que.front().weigh;
		val=que.front().value;
		lev=que.front().level;
		que.pop();
		if(val>res) //최댓값 검사 
			res=val;
		if(lev>=n) //레벨 끝 여부 검사 
			continue;
		//현재 레벨의 무게, 가치 저장 
		cur_weigh=arr[lev].first;  
		cur_value=arr[lev].second;
		
		if(we+cur_weigh<=k&&val+cur_value>dp[we+cur_weigh]){ //새로운 값을 더하는 경우 (dp값 검사 후 업데이트) 
			dp[we+cur_weigh]=val+cur_value;
			que.push(bag(we+cur_weigh,val+cur_value,lev+1));
		}
		if(val>=dp[we]){ //새로운 값을 더하지 않는 경우 (dp값 검사 후 업데이트) 
			dp[we]=val;
			que.push(bag(we,val,lev+1));
		}
	}
	printf("%d\n",res);
	return 0;
}

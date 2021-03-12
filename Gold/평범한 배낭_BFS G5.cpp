#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct bag{ //���繫��, ���簡ġ, ����ܰ踦 ���� 
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
	for(i=0;i<n;i++){ //�����͸� ���ͷ� ���� 
		scanf("%d%d",&n1,&n2);
		arr[i]=make_pair(n1,n2);
	}
	sort(arr.begin(),arr.end()); //���� ���Ժ��� ���� 
	que.push(bag(0,0,0));
	while(!que.empty()){
		//���� ����, ��ġ, ���� ���� 
		we=que.front().weigh;
		val=que.front().value;
		lev=que.front().level;
		que.pop();
		if(val>res) //�ִ� �˻� 
			res=val;
		if(lev>=n) //���� �� ���� �˻� 
			continue;
		//���� ������ ����, ��ġ ���� 
		cur_weigh=arr[lev].first;  
		cur_value=arr[lev].second;
		
		if(we+cur_weigh<=k&&val+cur_value>dp[we+cur_weigh]){ //���ο� ���� ���ϴ� ��� (dp�� �˻� �� ������Ʈ) 
			dp[we+cur_weigh]=val+cur_value;
			que.push(bag(we+cur_weigh,val+cur_value,lev+1));
		}
		if(val>=dp[we]){ //���ο� ���� ������ �ʴ� ��� (dp�� �˻� �� ������Ʈ) 
			dp[we]=val;
			que.push(bag(we,val,lev+1));
		}
	}
	printf("%d\n",res);
	return 0;
}

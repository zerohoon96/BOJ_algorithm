#include <stdio.h>
#include <vector>
#include <queue>
using namespace std; 
struct info{
	int cur,score,ct;
	info(int a,int b,int c){
		cur=a;
		score=b;
		ct=c;
	}
};
int main(void){
	int n,max_score=-1,i,cur,score,ct,tmp;
	int check[300][2]={0,};
	queue<info> que;
	scanf("%d",&n);
	vector<int> arr(n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	que.push(info(-1,0,0));
	while(!que.empty()){
		cur=que.front().cur;
		score=que.front().score;
		ct=que.front().ct;	
		que.pop();
		if(cur==n-1){
			if(score>max_score)
				max_score=score;
			continue;
		}
		if(ct<2){ //연속된 계단을 밟을 수 있는 경우 
			tmp=score+arr[cur+1];
			if(check[cur+1][ct]<tmp){  
				check[cur+1][ct]=tmp;
				que.push(info(cur+1,tmp,ct+1));
			}
		}
		if(cur+2<n){ //한번에 두 칸을 오를 수 있는 경우 
			tmp=score+arr[cur+2];
			if(check[cur+2][0]<tmp){
				check[cur+2][0]=tmp;
				que.push(info(cur+2,tmp,1));	
			}
		}
	}
	printf("%d\n",max_score);
	return 0;
}

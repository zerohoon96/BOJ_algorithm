#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
int arr[5001];
using namespace std;
int main(void){
	int n,cur;
	queue<int> que;
	scanf("%d",&n);
	que.push(n);
	
	while(!que.empty()){
		cur=que.front();
		que.pop();
		if(cur==0){
			printf("%d\n",arr[0]);
			exit(0);
		}
		if(cur-5>=0){
			if(arr[cur-5]==0){
				que.push(cur-5);
				arr[cur-5]=arr[cur]+1;
			}
		}
		if(cur-3>=0){
			if(arr[cur-3]==0){
				que.push(cur-3);
				arr[cur-3]=arr[cur]+1;
			}
		}
	}
	printf("-1\n");
	return 0;
}

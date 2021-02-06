#include <stdio.h>
#include <string.h>
#include <queue>
int length[200000]={-1,};
using namespace std;
int main(void){
	int n,k,cur;
	queue<int> que;
	scanf("%d%d",&n,&k);
	que.push(n);
	memset(length,-1,sizeof(int)*200000);
	length[n]=0;
	
	while(1){
		cur=que.front();
		que.pop();
		if(cur==k){
			printf("%d\n",length[k]);
			break;
		}
		if(cur<k){
			if(length[cur*2]<0){
				que.push(cur*2);
				length[cur*2]=length[cur]+1;
			}
			if(length[cur+1]<0){
				que.push(cur+1);
				length[cur+1]=length[cur]+1;
			}
		}
		if(cur>0){
			if(length[cur-1]<0){
				que.push(cur-1);
				length[cur-1]=length[cur]+1;
			}
		}
	}
	return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j;
	scanf("%d",&n);
	if(n%2!=0){ //홀수인 경우 타일을 모두 채울 수 없음 
		printf("0\n");
		return 0;
	}
	vector<int> dp(n/2+1);
	dp[0]=1;
	for(i=1;i<=n/2;i++){
		dp[i]=dp[i-1]*3; //길이가 2 늘어나는 경우 3배씩 늘어남 (길이 2일때 채우는 경우가 3개임) 
		for(j=0;j<i-1;j++)
			dp[i]+=dp[j]*2; //길이가 4부터 짝수개로 늘어나는 경우 2배씩 늘어남 (길이가 2보다 큰 짝수일때 채우는 경우가 2개임) 
	}
	printf("%d\n",dp[n/2]);
	return 0;
}

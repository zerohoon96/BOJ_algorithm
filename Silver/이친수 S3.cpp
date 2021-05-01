#include <stdio.h>
int n;
long long dp[91][2];
void pinary_number(int digit){
	if(digit>n)
		return;
	pinary_number(digit+1);
	if(dp[digit][0]==0&&digit>1)
		dp[digit][0]=dp[digit+1][0]+dp[digit+1][1];

	if(dp[digit][1]==0)
		dp[digit][1]=dp[digit+1][0];
}
int main(void){
	scanf("%d",&n);
	dp[n][0]=dp[n][1]=1;
	pinary_number(1);
	printf("%lld\n",dp[1][1]);
	return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,k,i,j,tmp;
	scanf("%d%d",&n,&k);
	vector<int> dp(k+1,0);
	dp[0]=1;
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		for(j=tmp;j<=k;j++)
			dp[j]+=dp[j-tmp];
	}
	printf("%d\n",dp[k]);
	return 0;
}

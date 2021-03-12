#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	vector<int> weigh(n+1),value(n+1);
	vector<vector<int> >dp(n+1,vector<int>(k+1));
	for(i=1;i<=n;i++){
		scanf("%d%d",&weigh[i],&value[i]);
		for(j=1;j<=k;j++){
			if(j-weigh[i]>=0)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-weigh[i]]+value[i]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	
	printf("%d\n",dp[n][k]);
	return 0;
}

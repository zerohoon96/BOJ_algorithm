#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	vector<int> weigh(n+1),value(n+1),dp(k+1);
	for(i=1;i<=n;i++)
		scanf("%d%d",&weigh[i],&value[i]);
		
	for(i=1;i<=n;i++){ //단계별로 진행 
		for(j=k;j>0;j--){ //각 단계에서 가방의 무게(0~k)에 따라 최대가치값 업데이트 
			if(j-weigh[i]>=0) //현재 단계 값을 넣을 수 있는 경우에 업데이트. 넣을 수 없으면 이전 값을 그대로 사용 
				dp[j]=max(dp[j-weigh[i]]+value[i],dp[j]);
		}
	}
	printf("%d\n",dp[k]);
	return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	vector<int> dp(k);
	for(i=0;i<k;i++) //dp�迭 �ʱ⼳�� 
		dp[i]=i+1;
	for(i=1;i<n;i++){ //�� ������Ʈ 
		for(j=1;j<k;j++){
			dp[j]+=dp[j-1];
			dp[j]%=1000000000;
		}
	}
	printf("%d\n",dp[k-1]); //��� ��� 
	return 0;
}

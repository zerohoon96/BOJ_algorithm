#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	vector<int> dp(k);
	for(i=0;i<k;i++) //dp배열 초기설정 
		dp[i]=i+1;
	for(i=1;i<n;i++){ //값 업데이트 
		for(j=1;j<k;j++){
			dp[j]+=dp[j-1];
			dp[j]%=1000000000;
		}
	}
	printf("%d\n",dp[k-1]); //결과 출력 
	return 0;
}

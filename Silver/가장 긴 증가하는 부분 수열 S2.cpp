#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j,tmp,res=-1;
	scanf("%d",&n);
	vector<int> arr(n),dp(n); //값 저장 백터, dp값 저장 백터 
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		tmp=-1;
		for(j=0;j<i;j++){ //이전값들이 입력된 현재값보다 작으면서 dp값이 최대인 값 구하기 
			if(arr[j]<arr[i]){
				if(dp[j]>tmp)
					tmp=dp[j];
			}
		}
		if(tmp<0) //이전 값들이 입력된 현재값보다 모두 큰 경우 1 저장 
			dp[i]=1;
		else //최댓값에 1 더해서 새로운 dp값 저장 
			dp[i]=tmp+1;
		if(dp[i]>res) //가장 긴 증가하는 부분수열 탐색 
			res=dp[i];
	}
	printf("%d\n",res); //결과값 출력 
	return 0;
}

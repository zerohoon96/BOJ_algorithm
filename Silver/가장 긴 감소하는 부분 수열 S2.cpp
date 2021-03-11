#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j,data,res=0;
	scanf("%d",&n);
	vector<int> arr(n),dp(n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=n-1;i>=0;i--){
		data=0;
		for(j=n-1;j>i;j--){ //이전 값중에서 적합한 dp값 추출 
			if(arr[j]<arr[i]&&dp[j]>data)
				data=dp[j];
		}
		dp[i]=data+1; //새로운 dp값 저장 
		if(dp[i]>res) //최댓값 검사 
			res=dp[i];
	}
	printf("%d\n",res);
	return 0;
} 

#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j;
	scanf("%d",&n);
	vector<int> arr(n);
	vector<long long> dp(21); 
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	dp[arr[0]]=1; //초기값 설정 
	for(i=1;i<n-1;i++){ //처음(초기값), 마지막(목표값)을 제외한 입력값 탐색 
		vector<long long> tmp(21);
		for(j=0;j<21;j++){ //현 단계 숫자를 연산(+,-)했을때 0~20가 나오는 경우의 수 저장 
			if(j-arr[i]>=0)
				tmp[j]+=dp[j-arr[i]]; 
			if(j+arr[i]<=20)
				tmp[j]+=dp[j+arr[i]];
		}
		dp=tmp; //dp 업데이트 
	}
	printf("%lld\n",dp[arr[n-1]]); //정답 출력 
	return 0;
}

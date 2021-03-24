#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(void){
	int n,i,j,arr[3],max_dp[3],min_dp[3],tmp_dp[3];
	scanf("%d",&n);
	for(i=0;i<3;i++) //초기 dp배열 초기화 
		scanf("%d",&max_dp[i]);
	memcpy(min_dp,max_dp,sizeof(int)*3);
	for(i=1;i<n;i++){ //입력과 동시에 dp값 업데이트 
		for(j=0;j<3;j++)
			scanf("%d",&arr[j]);
		//max dp 업데이트 (각 선택마다 최댓값을 선택하며 누적) 
		tmp_dp[0]=arr[0]+max(max_dp[0],max_dp[1]);
		tmp_dp[1]=arr[1]+max(max_dp[0],max(max_dp[1],max_dp[2]));
		tmp_dp[2]=arr[2]+max(max_dp[1],max_dp[2]);
		memcpy(max_dp,tmp_dp,sizeof(int)*3);
		//min dp 업데이트 (각 선택마다 최솟값을 선택하며 누적) 
		tmp_dp[0]=arr[0]+min(min_dp[0],min_dp[1]);
		tmp_dp[1]=arr[1]+min(min_dp[0],min(min_dp[1],min_dp[2]));
		tmp_dp[2]=arr[2]+min(min_dp[1],min_dp[2]);
		memcpy(min_dp,tmp_dp,sizeof(int)*3);
	}
	printf("%d %d\n",max(max_dp[0],max(max_dp[1],max_dp[2])),min(min_dp[0],min(min_dp[1],min_dp[2]))); //정답 출력 
	return 0;
}

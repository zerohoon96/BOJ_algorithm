#include <stdio.h>
#include <string.h>
#define LIMIT 1000000000 
int main(void){
	int i,j,n,res=0,dp[10],tmp[10];
	dp[0]=0; //초기 데이터 세팅 
	for(i=1;i<10;i++)
		dp[i]=1; 
	 
	scanf("%d",&n);
	for(i=1;i<n;i++){ //n-1번의 연산
		memcpy(tmp,dp,sizeof(int)*10); 
		memset(dp,0,sizeof(int)*10);
		for(j=0;j<10;j++){ //0~9까지 반복하며 새로운 dp값 누적시켜 저장 
			if(j>0) //j-1값 추가 
				dp[j-1]+=tmp[j];
			if(j<9) //j+1값 추가 
				dp[j+1]+=tmp[j];
		}
		for(j=0;j<10;j++) //범위 벗어나지 않게 10억으로 나눈 나머지로 저장 
			dp[j]%=LIMIT;
	}
	
	for(i=0;i<10;i++){ //정답 구하기 
		res+=dp[i];
		res%=LIMIT;
	}
	printf("%d\n",res);
	return 0;
}

#include <stdio.h>
#define MAX 100000000000000000
long long dp_1[100][100],dp_2[100][100];
void combination(int n,int r){
	if(n==r){ //nCn 의 경우 
		dp_2[n][r]=1;
		return;
	}
	if(r==1||n-r==1){ //nC1, nCn-1 의 경우 
		dp_2[n][r]=n;
		return;
	}
	if(dp_1[n][r]!=0||dp_2[n][r]!=0) //이미 구한 값이 dp에 있는 경우 
		return;
		
	combination(n-1,r); //n-1Cr 값 처리
	combination(n-1,r-1); //n-1Cr-1 값 처리 
	
	dp_1[n][r]=dp_1[n-1][r]+dp_1[n-1][r-1]; //앞부분 업데이트 
	dp_2[n][r]=dp_2[n-1][r]+dp_2[n-1][r-1]; //뒷부분 업데이트
	 
	if(dp_2[n][r]/MAX>0){ //carry가 발생한 경우 처리 
		dp_1[n][r]+=dp_2[n][r]/MAX;
		dp_2[n][r]%=MAX;
	}
}
int main(void){
	int n,r;
	long long res,digit=MAX/10;
	bool flag=false;
	scanf("%d%d",&n,&r);
	combination(n,r);
	if(dp_1[n][r]>0) //앞부분 출력 
		printf("%lld",dp_1[n][r]);
	
	while(digit>0){ //뒷부분 출력 
		res=dp_2[n][r]/digit;
		if(dp_1[n][r]>0||res>0||flag||digit==1){
			printf("%lld",res);
			flag=true;
		}
		dp_2[n][r]%=digit;
		digit/=10;
	}
	return 0;
}

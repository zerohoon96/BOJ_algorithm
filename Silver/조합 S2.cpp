#include <stdio.h>
#define MAX 100000000000000000
long long dp_1[100][100],dp_2[100][100];
void combination(int n,int r){
	if(n==r){ //nCn �� ��� 
		dp_2[n][r]=1;
		return;
	}
	if(r==1||n-r==1){ //nC1, nCn-1 �� ��� 
		dp_2[n][r]=n;
		return;
	}
	if(dp_1[n][r]!=0||dp_2[n][r]!=0) //�̹� ���� ���� dp�� �ִ� ��� 
		return;
		
	combination(n-1,r); //n-1Cr �� ó��
	combination(n-1,r-1); //n-1Cr-1 �� ó�� 
	
	dp_1[n][r]=dp_1[n-1][r]+dp_1[n-1][r-1]; //�պκ� ������Ʈ 
	dp_2[n][r]=dp_2[n-1][r]+dp_2[n-1][r-1]; //�޺κ� ������Ʈ
	 
	if(dp_2[n][r]/MAX>0){ //carry�� �߻��� ��� ó�� 
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
	if(dp_1[n][r]>0) //�պκ� ��� 
		printf("%lld",dp_1[n][r]);
	
	while(digit>0){ //�޺κ� ��� 
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

#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j;
	scanf("%d",&n);
	if(n%2!=0){ //Ȧ���� ��� Ÿ���� ��� ä�� �� ���� 
		printf("0\n");
		return 0;
	}
	vector<int> dp(n/2+1);
	dp[0]=1;
	for(i=1;i<=n/2;i++){
		dp[i]=dp[i-1]*3; //���̰� 2 �þ�� ��� 3�辿 �þ (���� 2�϶� ä��� ��찡 3����) 
		for(j=0;j<i-1;j++)
			dp[i]+=dp[j]*2; //���̰� 4���� ¦������ �þ�� ��� 2�辿 �þ (���̰� 2���� ū ¦���϶� ä��� ��찡 2����) 
	}
	printf("%d\n",dp[n/2]);
	return 0;
}

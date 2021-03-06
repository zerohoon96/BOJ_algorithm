#include <stdio.h>
#include <string.h>
#define LIMIT 1000000000 
int main(void){
	int i,j,n,res=0,dp[10],tmp[10];
	dp[0]=0; //�ʱ� ������ ���� 
	for(i=1;i<10;i++)
		dp[i]=1; 
	 
	scanf("%d",&n);
	for(i=1;i<n;i++){ //n-1���� ����
		memcpy(tmp,dp,sizeof(int)*10); 
		memset(dp,0,sizeof(int)*10);
		for(j=0;j<10;j++){ //0~9���� �ݺ��ϸ� ���ο� dp�� �������� ���� 
			if(j>0) //j-1�� �߰� 
				dp[j-1]+=tmp[j];
			if(j<9) //j+1�� �߰� 
				dp[j+1]+=tmp[j];
		}
		for(j=0;j<10;j++) //���� ����� �ʰ� 10������ ���� �������� ���� 
			dp[j]%=LIMIT;
	}
	
	for(i=0;i<10;i++){ //���� ���ϱ� 
		res+=dp[i];
		res%=LIMIT;
	}
	printf("%d\n",res);
	return 0;
}

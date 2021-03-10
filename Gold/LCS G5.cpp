#include <stdio.h>
#include <string.h>
int main(void){
	int i,j,n1,n2,dp[1000][1000];
	char str1[1000],str2[1000];
	scanf("%s%s",str1,str2);
	
	for(i=0;i<strlen(str2);i++){
		for(j=0;j<strlen(str1);j++){
			if(str1[j]==str2[i]){ //�� ���� ���� ��� 
				if(i==0||j==0)
					dp[i][j]=1;
				else
					dp[i][j]=dp[i-1][j-1]+1; //���� LCS��+1�� dp�� ���� 
			}
			else{ //�� ���� �ٸ� ��� 
				n1=n2=0;
				if(j>0)
					n1=dp[i][j-1];
				if(i>0)
					n2=dp[i-1][j];
				n1>n2?dp[i][j]=n1:dp[i][j]=n2; //�������� ���ʰ�, ���ʰ� �߿��� ū ���� dp�� ���� 
			}
		}
	}
	printf("%d\n",dp[strlen(str2)-1][strlen(str1)-1]);
	return 0;
}

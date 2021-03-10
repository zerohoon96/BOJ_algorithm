#include <stdio.h>
#include <string.h>
int main(void){
	int i,j,n1,n2,dp[1000][1000];
	char str1[1000],str2[1000];
	scanf("%s%s",str1,str2);
	
	for(i=0;i<strlen(str2);i++){
		for(j=0;j<strlen(str1);j++){
			if(str1[j]==str2[i]){ //두 값이 같은 경우 
				if(i==0||j==0)
					dp[i][j]=1;
				else
					dp[i][j]=dp[i-1][j-1]+1; //직전 LCS값+1을 dp에 저장 
			}
			else{ //두 값이 다른 경우 
				n1=n2=0;
				if(j>0)
					n1=dp[i][j-1];
				if(i>0)
					n2=dp[i-1][j];
				n1>n2?dp[i][j]=n1:dp[i][j]=n2; //직전값인 왼쪽값, 위쪽값 중에서 큰 값을 dp에 저장 
			}
		}
	}
	printf("%d\n",dp[strlen(str2)-1][strlen(str1)-1]);
	return 0;
}

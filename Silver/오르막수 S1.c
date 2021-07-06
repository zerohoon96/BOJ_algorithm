#include <stdio.h>
int main(void){
    int i,j,k,n,dp[10],tmp[10];
    scanf("%d",&n);
    for(i=0;i<10;i++)
        dp[i]=1;
    for(i=1;i<n;i++){
        for(j=0;j<10;j++)
            tmp[j]=0;
        for(j=0;j<10;j++){
            for(k=j;k<10;k++){
                tmp[k]+=dp[j];
                tmp[k]%=10007;
            }
        }
        for(j=0;j<10;j++)
            dp[j]=tmp[j];
    }
    n=0;
    for(i=0;i<10;i++){
        n+=dp[i];
        n%=10007;
    }
    printf("%d\n",n);
    return 0;
}
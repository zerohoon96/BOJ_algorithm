#include <stdio.h>
#include <string.h>
long long dp[31][31];
int n;
long long pill(int w,int h){
    long long n1=0,n2=0;
    if(dp[w][h]>0) //저장된 dp값 사용
        return dp[w][h];
    if(w+1<=n) //w가 n개보다 많이 사용하지 못하게 제한
        n1=pill(w+1,h);
    if(w>=h+1) //h가 w개보다 많이 사용하지 못하게 제한 (자동으로 h를 n개보다 많이 사용하지 못하게 제한됨)
        n2=pill(w,h+1);
    return dp[w][h]=n1+n2;
}

int main(void){
    while(1){
        scanf("%d",&n);
        if(n==0)
            break;
        dp[n][n]=1;
        printf("%lld\n",pill(0,0)); //dp로 진행
        memset(dp,0,sizeof(long long)*31*31); //dp 배열 초기화
    }
    return 0;
}
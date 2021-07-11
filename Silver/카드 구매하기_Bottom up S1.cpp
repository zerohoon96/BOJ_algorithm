#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[1001],arr[1001];
int main(void){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        dp[i]=arr[i];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<i;j++){
            dp[i]=max(dp[i],dp[i-j]+arr[j]);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
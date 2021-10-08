#include <stdio.h>
int dp[12];
int get_res(int cur){
    if(cur<0)
        return 0;
    if(dp[cur]>0)
        return dp[cur];
    return dp[cur]=get_res(cur-1)+get_res(cur-2)+get_res(cur-3);
}
int main(void){
    int i,n,num;
    scanf("%d",&n);
    dp[0]=1;
    for(i=0;i<n;i++){
        scanf("%d",&num);
        printf("%d\n",get_res(num));
    }
    return 0;
}
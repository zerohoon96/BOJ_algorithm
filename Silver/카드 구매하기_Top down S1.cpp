#include <stdio.h>
#include <vector>
using namespace std;
vector<int> arr,dp;
int n,res=0;
void card(int cost,int ct){ //Top down
    int i;
    if(ct==n){ //n개의 카드를 구매한 경우 최댓값 검사 후 return
        if(cost>res)
            res=cost;
        return;
    }
    dp[ct]=cost;
    for(i=1;i<=n;i++){ //1~n개의 카드를 추가하며 유망한 경우에만 진행
        if(ct+i<=n&&cost+arr[i-1]>dp[ct+i])
            card(cost+arr[i-1],ct+i);
    }
}
int main(void){
    int i;
    scanf("%d",&n);
    arr.resize(n,0);
    dp.resize(n+1,-1);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    card(0,0);
    printf("%d\n",res);
    return 0;
}
#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
    int n,i,j,res=-1;
    vector<int> dp,arr;
    scanf("%d",&n);
    arr.resize(n,0);
    dp.resize(n,0);
    for(i=0;i<n;i++){ //입력받으면서 LIS 구하기
        scanf("%d",&arr[i]);
        for(j=0;j<n-1;j++){ //입력값 및 이전 dp값 검사
            if(arr[j]<arr[i]&&dp[j]>dp[i])
                dp[i]=dp[j];
        }
        dp[i]++;
        if(dp[i]>res)
            res=dp[i];
    }
    printf("%d\n",n-res); //LIS를 제외한 나머지 숫자들만 이동하면 됨
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 2147000000
using namespace std;
int dp[500][500];
int arr[500],presum[500];
int func(int left,int right){
    int i,res=MAX,tmp;
    if(dp[left][right]>0){ //이미 dp에 저장된 값이 있으면 return
        return dp[left][right];
    }
    if(left==right) //범위가 한 파일이면 0 리턴 (한 파일은 비용이 발생하지 않음)
        return 0;
    for(i=left;i<right;i++){ //경계를 바꾸어가며 답 업데이트
        tmp=presum[right]-presum[left-1];
        res=min(res,func(left,i)+func(i+1,right)+tmp);
    }
    return dp[left][right]=res;
}
int main(void){
    int i,j,tc,n;
    scanf("%d",&tc);
    for(i=0;i<tc;i++){ //tc 수만큼 실행
        scanf("%d",&n);
        memset(dp,0,sizeof(int)*500*500);
        memset(arr,0,sizeof(int)*500);
        memset(presum,0,sizeof(int)*500);
        for(j=0;j<n;j++){
            scanf("%d",&arr[j]);
            presum[j]=arr[j];
            if(j>0) //누적합 저장
                presum[j]+=presum[j-1];
        }
        printf("%d\n",func(0,n-1)); //Top down 방식으로 해결 및 답 출력
    }
    return 0;
}
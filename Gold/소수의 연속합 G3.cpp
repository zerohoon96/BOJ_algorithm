#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
    int n,i,j,p=0,tmp=0,ct=0;
    vector<int> arr,prime;
    scanf("%d",&n);
    arr.resize(n+1,1);
    for(i=2;i<=n;i++){ //에라토스테네스의 체로 소수 리스트 생성
        if(arr[i]==0)
            continue;
        for(j=i*2;j<=n;j+=i)
            arr[j]=0;
    }
    prime.push_back(2);
    for(i=3;i<=n;i++){
        if(arr[i]==1)
            prime.push_back(i);
    }
    for(i=0;i<(int)prime.size();i++){ //투포인터로 연속된 소수합 구하기
        tmp+=prime[i];
        while(tmp>n)
            tmp-=prime[p++];
        if(tmp==n)
            ct++;
    }
    printf("%d\n",ct);
    return 0;
}
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int n,i,j;
    long long res=0;
    vector<int> arr;
    scanf("%d",&n);
    arr.resize(n,0);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr.begin(),arr.end());
    for(i=n-1;i>=0;i-=2){ //양수 처리 (반복문이 종료되면 i는 처음으로 양수가 아닌 수의 index)
        if(arr[i]<=0) //양수가 아니면 break
            break;
        if(i==0||arr[i-1]<=0){ //양수가 한 개 남으면 더하고 break
            res+=arr[i--];
            break;
        }
        if(arr[i]==1){ //현재 항이 1이면 곱하지 않고 더함
            res+=arr[i++];
            continue;
        }
        if(arr[i-1]==1){ //현재 항은 1보다 크지만 이전 항이 1이면 두 수를 더함
            res+=arr[i]+arr[i-1];
            continue;
        }
        res+=arr[i]*arr[i-1]; //두 개의 양수를 곱해서 더함
    }
    for(j=0;j<=i;j+=2){ //음수, 0은 절댓값이 큰 순서대로 연산
        if(j==i) //하나가 남은 경우 더함
            res+=arr[j];
        else
            res+=arr[j]*arr[j+1];
    }
    printf("%lld\n",res); //결과 출력
    return 0;
}
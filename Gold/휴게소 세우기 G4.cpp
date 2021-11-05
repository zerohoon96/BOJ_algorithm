#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int n,m,l,i;
    int left,right,mid,ct,res;
    vector<int> arr;
    scanf("%d%d%d",&n,&m,&l);
    arr.resize(n+2);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    left=arr[n]=0; //고속도로의 처음과 끝을 추가하고 정렬
    right=res=arr[n+1]=l;
    sort(arr.begin(),arr.end());
    while(left<=right){ //이분탐색으로 진행
        ct=0;
        mid=(left+right)/2;
        if(mid==0){
            left=mid+1;
            continue;
        }
        for(i=1;i<n+2;i++){ //각 구간에 mid 간격으로 휴게소를 배치할때 총 개수 계산
            ct+=(arr[i]-arr[i-1]-1)/mid;
            if(ct>m) //m개보다 많으면 중단
                break;
        }
        if(ct<=m){ //배치 가능한 휴게소 개수가 적당하면 저장하고 간격을 줄임
            res=mid;
            right=mid-1;
        }
        else{ //배치 가능한 휴게소 개수가 너무 많으면 간격을 늘림
            left=mid+1;
        }
    }
    printf("%d\n",res);
    return 0;
}

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> floor,ceiling;
int main(void){
    int n,h,i,tmp;
    int left,right,mid;
    scanf("%d%d",&n,&h);

    floor.resize(h+1,0);
    ceiling.resize(h+1,0);
    
    //입력과 동시에 석순, 종유석에 따른 데이터 분배 (순서가 반대이므로)
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        if(i%2==0)
            floor[tmp]++;
        else
            ceiling[h+1-tmp]++;
    }
    
    //석순 누적합
    for(i=h-1;i>0;i--)
        floor[i]+=floor[i+1];
    
    //종유석 누적합
    for(i=2;i<=h;i++)
        ceiling[i]+=ceiling[i-1];
    
    //석순, 종유석의 구간 누적합 합산
    for(i=1;i<=h;i++)
        floor[i]+=ceiling[i];

    sort(floor.begin(),floor.end());
    
    left=1;
    right=h;
    tmp=1;

    //최솟값의 마지막 위치 탐색
    while(left<=right){
        mid=(left+right)/2;
        if(floor[mid]==floor[tmp]){
            tmp=mid;
            left=mid+1;
        }
        else
            right=mid-1;
    }

    //정답 출력
    printf("%d %d\n",floor[tmp],tmp);
    return 0;
}
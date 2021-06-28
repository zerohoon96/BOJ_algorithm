#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int i,n,c;
    int left,right,mid,ct,prev,res=0;
    scanf("%d%d",&n,&c);
    vector<int> router(n);
    for(i=0;i<n;i++)
        scanf("%d",&router[i]);

    //공유기 백터 정렬 및 초기 left, right 설정
    sort(router.begin(),router.end());
    left=1;
    right=router[n-1]-router[0];
    
    //이분탐색으로 최적의 간격 찾기
    while(left<=right){
        ct=1;
        mid=(left+right)/2;
        prev=0;
        
        //현재 간격에서 설치할 수 있는 공유기 개수 탐색
        for(i=1;i<n;i++){
            if(router[prev]+mid<=router[i]){
                ct++;
                prev=i;
                if(ct>c)
                    break;
            }
        }

        if(ct>=c){ //설치 가능한 공유기가 많거나 같으면 임시저장후 간격을 늘림 (답이 될 수 있음)
            left=mid+1;
            res=mid;
        }
        else if(ct<c) //설치 가능한 공유기가 부족하면 간격을 줄임
            right=mid-1;
    }

    //정답 출력
    printf("%d\n",res);
    return 0;
}
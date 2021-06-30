#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define MAX 2000000000
using namespace std;
int main(void){
    int n,i;
    int left,right,mid,diff,tmp_min,total_min=MAX;
    vector<int> liquid;
    pair<int,int> tmp_res,total_res;
    
    //백터 resize 및 용액값 입력
    scanf("%d",&n);
    liquid.resize(n,0);
    for(i=0;i<n;i++)
        scanf("%d",&liquid[i]);

    //백터 정렬 후 인덱스별로 더했을때 가장 0에 가까운 인덱스 저장
    sort(liquid.begin(),liquid.end());
    for(i=0;i<n-1;i++){
        left=i+1;
        right=n-1;
        tmp_res.first=liquid[i];
        tmp_min=MAX;

        //이분탐색으로 i번째 원소와 더했을때 가장 0에 가까운 인덱스 탐색
        while(left<=right){
            mid=(left+right)/2;
            diff=liquid[i]+liquid[mid];
            if(diff==0){ //계산값이 0인 경우 프로그램 종료
                printf("%d %d\n",liquid[i],liquid[mid]);
                return 0;
            }
            if(abs(diff)<tmp_min){ //계산 값이 이전 값보다 0에 더 가까운 경우 업데이트
                tmp_res.second=liquid[mid];
                tmp_min=abs(diff);
            }
            if(diff>0) //계산 값이 양수면 작은 값으로 (0과 가까운 방향이 작은 값)
                right=mid-1;
            else //계산 값이 음수면 큰 값으로 (0과 가까운 방향이 큰 값)
                left=mid+1;
        }
        //정답 검사
        if(tmp_min<total_min){
            total_res=tmp_res;
            total_min=tmp_min;
        }
    }

    //정답 출력
    printf("%d %d\n",total_res.first,total_res.second);
    return 0;
}
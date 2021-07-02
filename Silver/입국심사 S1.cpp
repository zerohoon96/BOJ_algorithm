#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
    int n,m,i;
    long long left=1,right=0,mid,tmp,res;
    vector<int> vec;
    scanf("%d%d",&n,&m);
    vec.resize(n,0);
    for(i=0;i<n;i++){ //자리 입력과 동시에 최댓값 탐색
        scanf("%d",&vec[i]);
        if(vec[i]>right)
            right=vec[i];
    }

    //인원수만큼 최댓값을 곱해서 right 설정
    right*=m;
    while(left<=right){
        mid=(left+right)/2;
        tmp=0;
        //현재 시간으로 모든 자리에서 처리를 할때 가능한 인원수 저장
        for(i=0;i<n;i++)
            tmp+=mid/vec[i];
        if(tmp>=m){ //현재 시간으로 m명 이상 처리가 가능하므로 시간을 줄임
            res=mid;
            right=mid-1;
        }
        else //현재 시간으로 m명 처리가 불가능하므로 시간을 늘림
            left=mid+1;
    }
    printf("%lld\n",res);
    return 0;
}
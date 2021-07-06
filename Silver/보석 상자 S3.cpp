#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
    int n,m,i;
    int left=1,right=0,mid,tmp,res=0;
    vector<int> jewel;
    scanf("%d%d",&n,&m);
    jewel.resize(m);
    for(i=0;i<m;i++){ //입력과 동시에 right값 설정 (입력 보석값중 최댓값)
        scanf("%d",&jewel[i]);
        if(jewel[i]>right)
            right=jewel[i];
    }
    while(left<=right){ //이분탐색
        mid=(left+right)/2;
        printf("%d %d %d\n",left,mid,right);
        tmp=0;
        for(i=0;i<m;i++){ //각 보석을 mid개씩 나눠줄때 필요한 학생 수 계산
            tmp+=jewel[i]/mid;
            if(jewel[i]%mid>0)
                tmp++;
        }
        if(tmp>n){ //필요한 학생 수가 많으면 할당 보석 수를 늘림
            left=mid+1;
        }
        else{ //필요한 학생 수가 적으면 임시저장 후 할당 보석 수를 줄임 (최소화)
            res=mid;
            right=mid-1;
        }
    }
    printf("%d\n",res);
    return 0;
}
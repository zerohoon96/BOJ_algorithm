#include <stdio.h>
int main(void){
    long long x,y;
    long long left=1,right,mid,init,cur,res=-1;
    scanf("%lld%lld",&x,&y);
    init=y*100/x;
    if(init>=99){ //현재 확률이 99% 이상인 경우 100%로 바꿀 수 없음
        printf("-1\n");
        return 0;
    }
    right=x; //right는 x로 설정 (x 더하면 무조건 1이상 차이 발생)
    while(left<=right){ //이분탐색으로 진행
        mid=(left+right)/2;
        cur=(y+mid)*100/(x+mid);
        if(cur>init){ //초깃 승률보다 현재 승률이 크면 mid를 저장하고 범위를 줄임
            res=mid;
            right=mid-1;
        }
        else //초기 승률과 같으면 (작은 경우는 없음) mid를 감소시킴
            left=mid+1;
    }
    printf("%lld\n",res);
    return 0;
}
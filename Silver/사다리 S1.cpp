#include <stdio.h>
#include <math.h>
double x,y,c;
double get_res(double val){ //현재 예측값으로 예측값을 계산
    double n1,n2,res;
    n1=1/sqrt(x*x-val*val);
    n2=1/sqrt(y*y-val*val);
    res=c*val*(n1+n2);
    return res;
}
int main(void){
    double left=0,right,mid,res=0,tmp;
    scanf("%lf%lf%lf",&x,&y,&c);
    x<y?right=x:right=y;
    while(left<=right){ //이진탐색으로 최적의 거리 탐색
        mid=(left+right)/2;
        tmp=get_res(mid);
        if(tmp>mid) //예측값이 예측값으로 예측한 값보다 크면 길이를 줄임 
            right=mid-0.000001;
        else{ //예측값이 예측값으로 예측한 값보다 작으면 임시저장 후 길이를 늘림
            res=mid;
            left=mid+0.000001;
        }
    }
    res+=0.0005; //소숫점 셋째자리에서 반올림
    printf("%.3lf\n",res); //결과 출력
    return 0;
}
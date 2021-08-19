#include <stdio.h>
int main(void){
    int k,i;
    long long n,left_1,right_1,mid_1,left_2,right_2,mid_2,res_1=0,res_2=0,tmp_res;
    scanf("%lld%d",&n,&k);
    left_1=1;
    right_1=n*n;
    while(left_1<=right_1){ //1~n*n 범위의 수를 이진탐색으로 검사
        res_2=0;
        mid_1=(left_1+right_1)/2;
        for(i=1;i<=n;i++){ //1~n의 모든 행에서 mid_1보다 작은 수의 개수 구하기
            left_2=1;
            right_2=n;
            tmp_res=0;
            while(left_2<=right_2){
                mid_2=(left_2+right_2)/2;
                if(i*mid_2<mid_1){ //현재 행의 mid_2가 mid_1보다 작으면 임시저장 후 오른쪽으로
                    tmp_res=mid_2;
                    left_2=mid_2+1;
                }
                else{ //현재 행의 mid_2가 mid_1보다 크거나 같으면 왼쪽으로
                    right_2=mid_2-1;
                }
            }
            res_2+=tmp_res;
            if(res_2>=k) //이미 k개의 수를 넘어갔으면 break
                break;
        }
        if(res_2<k){ //mid_1보다 작은 수의 개수가 k보다 작으면 임시저장 후 오른쪽으로
            res_1=mid_1;
            left_1=mid_1+1;
        }
        else{ //mid_1보다 작은 수의 개수가 k보다 크거나 같으면 왼쪽으로 (답이 아님)
            right_1=mid_1-1;
        }
    }
    printf("%lld\n",res_1);
    return 0;
}
#include <stdio.h>
#include <vector>
#define MAX 100000
using namespace std;
int main(void){
    int n,m,i;
    int left=1,right=0,mid,res;
    long long tmp;
    vector<int> budget;
    scanf("%d",&n);
    budget.resize(n,0);
    for(i=0;i<n;i++){ //입력과 동시에 right 선정
        scanf("%d",&budget[i]);
        if(budget[i]>right)
            right=budget[i];
    }
    scanf("%d",&m);

    //이진탐색으로 최대 상한액 탐색
    while(left<=right){
        mid=(left+right)/2;
        tmp=0;
        for(i=0;i<n;i++){ //현재 상한액에서의 총 예산 계산
            tmp+=mid>budget[i]?budget[i]:mid;
            if(tmp>m)
                break;
        }
        if(tmp<m){ //총 예산보다 낮으면 상한액을 늘림
            res=mid;
            left=mid+1;
        }
        else if(tmp>m) //총 예산보다 크면 상한액을 낮춤
            right=mid-1;
        else{ //총 예산액과 같으면 종료
            res=mid;
            break;   
        }
    }
    printf("%d\n",res);
    return 0;
}
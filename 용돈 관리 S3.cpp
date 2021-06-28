#include <stdio.h>
#include <vector>
using namespace std;
int i,n,m;
vector<int> plan;
int get_ct(int money){
    int ct=1,cur=money;
    for(i=0;i<n;i++){ //전체 탐색
        if(plan[i]>cur){ //현재 가지고 있는 금액보다 큰 경우 인출 후 사용
            cur=money-plan[i];
            ct++;
        }
        else //현재 금액으로 사용할 수 있으면 사용
            cur-=plan[i];
        if(ct>m)
            return ct;
    }
    return ct;
}

int main(void){
    int mid,left=-1,right=1000000000;
    int tmp,min_money=-1,ct=0,res=0;
    scanf("%d%d",&n,&m);
    
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        plan.push_back(tmp);
        if(tmp>left)
            left=tmp;
    }

    while(left<=right){
        mid=(left+right)/2;
        ct=get_ct(mid);
        if(ct<=m){ //인출 횟수가 m보다 같거나 작은 경우 금액을 줄여서 최소 금액을 찾음
            right=mid-1;
            res=mid;
        }
        else if(ct>m) //인출 횟수가 m보다 크면 금액을 늘려서 횟수를 줄임
            left=mid+1;
    }

    printf("%d\n",res); //정답 출력
    return 0;
}
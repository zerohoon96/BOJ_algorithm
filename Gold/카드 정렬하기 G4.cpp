#include <stdio.h>
#include <queue>
using namespace std;
int main(void){
    int n,tmp,i;
    long long res=0;
    priority_queue<int> que;
    scanf("%d",&n);
    for(i=0;i<n;i++){ //입력과 동시에 우선순위큐에 값을 음수로 저장 (오름차순을 위해)
        scanf("%d",&tmp);
        que.push(-tmp);
    }
    while(que.size()>1){ //큐의 크기가 1이 될 때까지 반복 (더이상 비교 대상이 없을 때까지)
        tmp=res;
        res+=-que.top(); //두 묶음을 합치는데 필요한 비교 수 저장
        que.pop();
        res+=-que.top();
        que.pop();
        que.push(-(res-tmp)); //새롭게 합쳐진 카드 묶음을 저장
    }
    printf("%lld\n",res);
    return 0;
}
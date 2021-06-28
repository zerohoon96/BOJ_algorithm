#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
    int n,m,i;
    int left=0,right=-1,mid,res;
    long long ct;
    scanf("%d%d",&n,&m);
    vector<int> trees(n);
    
    //나무 높이 입력
    for(i=0;i<n;i++){
        scanf("%d",&trees[i]);
        if(trees[i]>right)
            right=trees[i];
    }

    //0 ~ 입력최댓값 범위에서 최적의 높이 탐색
    while(left<=right){
        mid=(left+right)/2;
        ct=0;
        for(i=0;i<n;i++){
            if(trees[i]>mid)
                ct+=trees[i]-mid;
        }
        if(ct>m){ //m보다 더 많이 자른 경우 임시로 저장하고 높이를 높임  (최대한 덜 자르기 위해)
            res=mid;
            left=mid+1;
        }
        else if(ct<m) //m보다 더 조금 자른 경우 높이를 낮춤 (아직 목표 m에 도달하지 않음)
            right=mid-1;
        else{ //m만큼 자른 경우 break (더 이상 높이거나 낮출 필요가 없음)
            res=mid;
            break;
        }
    }

    //정답 출력
    printf("%d\n",res);
    return 0;
}
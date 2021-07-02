#include <stdio.h>
#include <stdlib.h>
int main(void){
    int n,m,i;
    int *arr;
    long long left=1,right=0,mid,tmp,res;
    arr=(int*)malloc(sizeof(int)*n);
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){ //자리 입력과 동시에 최댓값 탐색
        scanf("%d",&arr[i]);
        if(arr[i]>right)
            right=arr[i];
    }
    //인원수만큼 최댓값을 곱해서 right 설정
    right*=m;
    while(left<=right){
        mid=(left+right)/2;
        tmp=0;
        //현재 시간으로 모든 자리에서 처리를 할때 가능한 인원수 저장
        for(i=0;i<n;i++)
            tmp+=mid/arr[i];
        if(tmp>=m){ //현재 시간으로 m명 이상 처리가 가능하므로 시간을 줄임
            res=mid;
            right=mid-1;
        }
        else //현재 시간으로 m명 처리가 불가능하므로 시간을 늘림
            left=mid+1;
    }
    printf("%lld\n",res);
    free(arr);
    return 0;
}
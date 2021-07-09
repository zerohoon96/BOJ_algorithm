#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
    int n,s,i,cur=0,tmp=0,res;
    vector<int> arr;
    scanf("%d%d",&n,&s);
    arr.resize(n,0);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    res=n+1;
    for(i=0;i<n;i++){ //배열 끝까지 진행
        tmp+=arr[i];
        if(tmp>=s){ //현재 합이 s보다 크면 커서를 앞으로 진행시키며 결과 업데이트
            while(tmp>=s){
                if(i-cur+1<res)
                    res=i-cur+1;
                tmp-=arr[cur++];
            }
        }
    }
    if(res>n) //결과 출력
        printf("0\n");
    else
        printf("%d\n",res);
    return 0;
}
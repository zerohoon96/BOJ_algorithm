#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
vector<int> arr;
int target,num;
void dp(int n,int ct){
    if(n==target||ct>arr[target]){
        return;
    }
    for(int i=num;i>0;i--){
        if(n+i*i>target||arr[n+i*i]<=ct+1)
            continue;
        arr[n+i*i]=ct+1;
        dp(n+i*i,ct+1);
    }
}
int main(void){
    scanf("%d",&target);
    num=sqrt(target);
    arr.resize(target+1,target+1);
    dp(0,0);
    printf("%d\n",arr[target]);
    return 0;
}
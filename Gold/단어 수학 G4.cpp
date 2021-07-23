#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int n,i,j,digit,num,res=0;
    char buf[10];
    vector<int> arr(26,0);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",buf);
        digit=1;
        for(j=strlen(buf)-1;j>=0;j--){
            arr[buf[j]-65]+=digit;
            digit*=10;
        }
    }
    sort(arr.begin(),arr.end());
    num=9;
    for(i=25;i>=0;i--){
        if(num<0)
            break;
        res+=arr[i]*num--;
    }
    printf("%d\n",res);
    return 0;
}
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int n,i,x,tmp,p1,p2,ct=0;
    vector<int> arr;
    scanf("%d",&n);
    arr.resize(n,0);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr.begin(),arr.end());
    scanf("%d",&x);
    p1=0;
    p2=n-1;
    while(p1<p2){ //Two pointers
        tmp=arr[p1]+arr[p2];
        if(tmp<x)
            p1++;
        else if(tmp>x)
            p2--;
        else{
            ct++;
            p1++;
            p2--;
        }
    }
    printf("%d\n",ct);
    return 0;
}
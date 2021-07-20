#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(void){
    int n,i,p1,p2,res,ct=0;
    vector<int> arr;
    map<int,bool> success;
    scanf("%d",&n);
    arr.resize(n,0);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        success.insert(make_pair(arr[i],false));
    }
    sort(arr.begin(),arr.end());
    for(i=0;i<n;i++){
        if(success[arr[i]]){ //이전에 추가된 수이면 continue
            ct++;
            continue;
        }
        p1=0;
        p2=n-1;
        while(p1<p2){ //Two pointer
            if(p1==i){
                p1++;
                continue;
            }
            if(p2==i){
                p2--;
                continue;
            }
            res=arr[p1]+arr[p2];
            if(res==arr[i]){ //더한 값이 현재 수와 일치하면 break
                ct++;
                success[arr[i]]=true;
                break;
            }
            else if(res<arr[i]) //더한 값이 현재 수보다 작으면 p1을 증가시켜서 계산값을 증가
                p1++;
            else //더한 값이 현재 수보다 크면 p2를 감소시켜서 계산값을 감소
                p2--;
        }
    }
    printf("%d\n",ct);
    return 0;
}
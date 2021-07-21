#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
    int n,i;
    vector<int> input,check;
    scanf("%d",&n);
    input.resize(n,0);
    check.resize(n+1,0);
    for(i=0;i<n;i++){
        scanf("%d",&input[i]);
        if(check[input[i]]>0){ //이미 저장된 수가 있으면 continue
            printf("%d ",check[input[i]]);
            continue;
        }
        if(input[i]>1){
            if(check[input[i]-1]==0){ //최소화를 위해 -1을 했는데 가능한 경우 양쪽 모두 설정 (양쪽을 모두 설정하지 않으면 빈자리가 생김)
                check[input[i]-1]=input[i];
                check[input[i]]=input[i]-1;
                continue;
            }
        }
        check[input[i]]=input[i]; //-1로 설정이 불가능하면 현재 숫자로 저장
        printf("%d ",check[input[i]]);
    }
    return 0;
}
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> arr;
int Find(int a){ //Find 함수
    if(arr[a]==a)
        return a;
    else
        return arr[a]=Find(arr[a]);
}
void Union(int a,int b){ //Union 함수
    a=Find(a);
    b=Find(b);
    arr[a]=b;
}
int main(void){
    int n,m,i,command,n1,n2;
    scanf("%d%d",&n,&m);
    arr.resize(n+1);
    for(i=0;i<n+1;i++) //벡터 초기화
        arr[i]=i;
    for(i=0;i<m;i++){ //m번의 명령어 입력
        scanf("%d%d%d",&command,&n1,&n2);
        if(command==1){ //같은 집합 판별 연산
            if(Find(n1)==Find(n2))
                puts("YES");
            else
                puts("NO");
        }
        else //합집합 연산
            Union(n1,n2);
    }
    return 0;
}
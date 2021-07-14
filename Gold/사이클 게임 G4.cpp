#include <stdio.h>
#include <vector>
using namespace std;
vector<int> link;
int Find(int n){
    if(n==link[n])
        return n;
    else
        return link[n]=Find(link[n]);
}
bool Union(int n1,int n2){
    n1=Find(n1);
    n2=Find(n2);
    if(n1==n2)
        return false;
    link[n1]=n2;
    return true;
}
int main(void){
    int i,n,m,v1,v2;
    scanf("%d%d",&n,&m);
    link.resize(n,0);
    for(i=0;i<n;i++) //초기 설정
        link[i]=i;
    for(i=1;i<=m;i++){
        scanf("%d%d",&v1,&v2);
        if(!Union(v1,v2)) //두 점이 같은 집합에 속해있으면 break
            break;
    }
    if(i<=m) //중간에 끝났으면 종료 지점 출력
        printf("%d\n",i);
    else //끝나지 않았으면 0 출력
        printf("0\n");
    return 0;
}
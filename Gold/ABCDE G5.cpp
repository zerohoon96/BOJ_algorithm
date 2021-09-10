#include <stdio.h>
#include <vector>
using namespace std;
int n,m;
bool success=false;
vector<vector<int> > list;
vector<bool> visit;
void DFS(int cur,int ct){
    int i;
    if(ct==4){ //4번 연속 연결에 성공한 경우 종료
        success=true;
        return;
    }
    for(i=0;i<(int)list[cur].size();i++){ //i번째 친구의 모든 친구관계 탐색
        if(visit[list[cur][i]]) //이미 연결한 친구면 continue
            continue;
        visit[list[cur][i]]=true;
        DFS(list[cur][i],ct+1);
        visit[list[cur][i]]=false;
        if(success) //연결에 성공한 경우 return
            return;
    }
}
int main(void){
    int i,n1,n2;
    scanf("%d%d",&n,&m);
    list.resize(n); 
    visit.resize(n,false);
    for(i=0;i<m;i++){
        scanf("%d%d",&n1,&n2);
        list[n1].push_back(n2); //인접리스트 저장 (양방향 이므로 2번 저장)
        list[n2].push_back(n1);
    }
    for(i=0;i<n;i++){ //모든 사람에 대해서 DFS 실행
        visit[i]=true;
        DFS(i,0);
        visit[i]=false;
        if(success) //성공했으면 종료
            break;
    }
    if(success) //정답 출력
        printf("1\n");
    else
        printf("0\n");
    return 0;
}
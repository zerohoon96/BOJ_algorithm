#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int,int> > > info;
int n,e;
int dijkstra(int start,int end){ //다익스트라 알고리즘으로 start와 end 사이의  최단경로 구하기
    int val,cur,tmp_n,tmp_val,i;
    vector<int> check(n+1,-1); //현재까지 start에서의 최단거리 저장
    vector<bool> visit(n+1,false); //선택 여부 저장
    priority_queue<pair<int,int> > que; //최단거리 노드를 선택하기 위한 우선순위큐
    check[start]=0;
    que.push(make_pair(0,start));
    while(!que.empty()){
            
        val=-que.top().first; //현재 가장 작은 가중치를 가지는 노드, 값 저장
        cur=que.top().second;
        que.pop();
        if(visit[cur]) //이미 방문한 노드인 경우 continue
            continue;
        if(cur==end) //end 노드에 도착한 경우 종료
            return val;
        visit[cur]=true;
        for(i=0;i<(int)info[cur].size();i++){ //새로운 노드를 선택했을때 최단거리 업데이트
            tmp_n=info[cur][i].first;
            tmp_val=info[cur][i].second;
            if(!visit[tmp_n]&&(check[tmp_n]<0||check[tmp_n]>check[cur]+tmp_val)){ //방문하지 않았고 현재값이 INF 이거나 새로운 값이 더 작으면 업데이트
                check[tmp_n]=check[cur]+tmp_val;
                que.push(make_pair(-check[tmp_n],tmp_n));
            }
        }
    }
    return -1; //두 노드가 연결되어 있지 않음
}

int main(void){
    int i,n1,n2,p1,p2,val,res1,res2,mid_res;
    scanf("%d%d",&n,&e);
    info.resize(n+1);
    for(i=0;i<e;i++){ //간선 정보를 입력받으면서 인접리스트 생성 (양방향 그래프이므로 2번 추가)
        scanf("%d%d%d",&n1,&n2,&val);
        info[n1].push_back(make_pair(n2,val));
        info[n2].push_back(make_pair(n1,val));
    }
    scanf("%d%d",&p1,&p2);
    mid_res=dijkstra(p1,p2); //경유지1과 경유지2 사이의 최단경로 저장
    if(mid_res<0){ //두 경유지가 연결되어 있지 않으면 답을 구할 수 없음
        printf("-1\n");
        return 0;
    }
    res1=res2=-1;
    if(((n1=dijkstra(1,p1))>=0)&&((n2=dijkstra(p2,n))>=0))
        res1=n1+mid_res+n2;  // (1 -> 경유지1) + (경유지1 -> 경유지2) + (경유지2 -> n)
    if(((n1=dijkstra(1,p2))>=0)&&((n2=dijkstra(p1,n))>=0))
        res2=n1+mid_res+n2;  // (1 -> 경유지2) + (경유지2 -> 경유지1) + (경유지1 -> n)

    if(res1<0&&res2<0) //두 경우 모두 답을 구하지 못함
        printf("-1\n");
    else if(res1<0) //res1에서 답을 구하지 못함
        printf("%d\n",res2);
    else if(res2<0) //res2에서 답을 구하지 못함
        printf("%d\n",res1);
    else //두 방법이 모두 성공했으면 작은값 출력
        printf("%d\n",res1<res2?res1:res2);
    return 0;
}
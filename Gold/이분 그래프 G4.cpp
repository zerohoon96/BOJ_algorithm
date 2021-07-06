#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> link;
int Find(int v){ //Find 함수
    if(v==link[v])
        return v;
    else
        return link[v]=Find(link[v]);
}
void Union(int v1,int v2){ //Union 함수
    v1=Find(v1);
    v2=Find(v2);
    link[v2]=v1;
}
int main(void){
    int i,j,r,k,v,e,v1,v2,cur,ct,tmp;
    bool res;
    scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d%d",&v,&e);
        vector<vector<int> > vertex(v+1);
        vector<int> high_nodes;
        vector<bool> check(v+1,false);
        link.resize(v+1,0);
        res=true;
        for(j=1;j<=v;j++) //link 백터 초기화
            link[j]=j;
        for(j=0;j<e;j++){ //입력을 받으면서 인접 리스트 생성, Union
            scanf("%d%d",&v1,&v2);
            vertex[v1].push_back(v2);
            Union(v1,v2);
        }
        for(j=1;j<=v;j++){ //Find를 통해서 최고 노드 리스트 생성
            tmp=Find(j);
            if(!check[tmp]){
                high_nodes.push_back(tmp);
                check[tmp]=true;
            }
        }
        for(j=0;j<(int)high_nodes.size();j++){ //최고 노드 개수만큼 BFS 실행
            if(vertex[high_nodes[j]].size()==0){
                continue;
            }
            queue<pair<int,int> > que;
            vector<bool> set_1(v+1,false),set_2(v+1,false);
            que.push(make_pair(high_nodes[j],0));
            while(!que.empty()){ //BFS
                cur=que.front().first;
                ct=que.front().second;
                que.pop();
                if(ct%2==0){ //정점을 넣을 순서가 첫 번째 집합
                    if(set_2[cur]){
                        res=false;
                        break;
                    }
                    set_1[cur]=true;
                }
                else{ //정점을 넣을 순서가 두 번째 집합
                    if(set_1[cur]){
                        res=false;
                        break;
                    }
                    set_2[cur]=true;
                }
                for(r=0;r<(int)vertex[cur].size();r++){ //연결된 정점들을 que에 push
                    que.push(make_pair(vertex[cur][r],ct+1));
                }
                vertex[cur].clear(); //무한루프 방지를 위한 현재 정점 인접리스트 clear
            }
            if(!res) //NO인 경우 종료
                break;
        }
        if(res) //결과 출력
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
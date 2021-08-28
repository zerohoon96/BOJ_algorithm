#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
    int n,m,i,j,k;
    int v1,v2,val;
    long long res;
    vector<vector<pair<int,int> > > info; //도시 연결 정보를 인접 리스트로 관리
    vector<long long> cur,tmp;
    vector<bool> visit,tmp_visit;
    scanf("%d%d",&n,&m);
    info.resize(n+1);
    cur.resize(n+1,-1);
    tmp.resize(n+1,-1);
    visit.resize(n+1,false);
    tmp_visit.resize(n+1,false);
    cur[1]=tmp[1]=0;
    visit[1]=tmp_visit[1]=true;
    for(i=0;i<m;i++){ //입력과 동시에 저장
        scanf("%d%d%d",&v1,&v2,&val);
        info[v1].push_back(make_pair(v2,val));
    }
    for(i=0;i<n;i++){ //n-1번 업데이트 (n번재 업데이트는 음의 사이클 검사)
        for(j=1;j<=n;j++){ //모든 도시를 검사하며 업데이트
            if(!visit[j]) //현재 도시가 탐색되지 않은 경우 continue
                continue;
            for(k=0;k<(int)info[j].size();k++){ //현재 도시와 인접한 도시들을 검사하며 relax
                v1=info[j][k].first;
                val=info[j][k].second;
                res=cur[j]+val;
                if(!tmp_visit[v1]||tmp[v1]>res){
                    if(i==n-1){ //n번째에서 값이 업데이트된 경우 음의 사이클
                        printf("-1\n");
                        return 0;
                    }
                    tmp[v1]=res;
                    tmp_visit[v1]=true;
                }
            }
        }
        cur=tmp;
        visit=tmp_visit;
    }
    for(i=2;i<=n;i++) //정답 출력
        printf("%lld\n",cur[i]);
    return 0;
}
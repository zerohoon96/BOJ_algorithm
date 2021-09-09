#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int main(void){
    int n,m,x,n1,n2,val,weigh,tmp_res,res=0;
    int i,j;
    vector<vector<pair<int,int> > > info;
    scanf("%d%d%d",&n,&m,&x);
    info.resize(n+1);

    for(i=0;i<m;i++){ //인접 리스트 생성
        scanf("%d%d%d",&n1,&n2,&weigh);
        info[n1].push_back(make_pair(n2,weigh));
    }
    for(i=1;i<=n;i++){ //x노드를 제외한 모든 경우 탐색
        if(i==x)
            continue;
        vector<int> check_1(n+1,-1);
        vector<bool> visit_1(n+1,false);
        priority_queue<pair<int,int> > que_1;
        check_1[i]=0;
        visit_1[i]=true;
        que_1.push(make_pair(0,i));
        while(1){
            val=-que_1.top().first;
            n1=que_1.top().second;
            que_1.pop();
            if(n1==x) //x 노드에 도착했으면 break
                break;
            visit_1[n1]=true; //새로 선택한 노드 방문 처리
            for(j=0;j<(int)info[n1].size();j++){
                n2=info[n1][j].first;
                weigh=info[n1][j].second;
                if(!visit_1[n2]&&(check_1[n2]<0||check_1[n1]+weigh<check_1[n2])){ //relax 연산 실행 (아직 선택되지 않았고 업데이트 대상인 경우)
                    check_1[n2]=check_1[n1]+weigh;
                    que_1.push(make_pair(-check_1[n2],n2));
                }
            }
        }
        tmp_res=check_1[x];

        vector<int> check_2(n+1,-1);
        vector<bool> visit_2(n+1,false);
        priority_queue<pair<int,int> > que_2;
        check_2[x]=0;
        visit_2[x]=true;
        que_2.push(make_pair(0,x));
        while(1){ //i 노드에 도착할 때까지 반복
            val=-que_2.top().first;
            n1=que_2.top().second;
            que_2.pop();
            if(n1==i) //i 노드에 도착했으면 break
                break;
            visit_2[n1]=true; //새로 선택한 노드 방문 처리
            for(j=0;j<(int)info[n1].size();j++){
                n2=info[n1][j].first;
                weigh=info[n1][j].second;
                if(!visit_2[n2]&&(check_2[n2]<0||check_2[n1]+weigh<check_2[n2])){ //relax 연산 실행 (아직 선택되지 않았고 업데이트 대상인 경우)
                    check_2[n2]=check_2[n1]+weigh;
                    que_2.push(make_pair(-check_2[n2],n2));
                }
            }
        }
        tmp_res+=check_2[i];
        if(res<tmp_res) //최장거리값 업데이트
            res=tmp_res;
    }
    printf("%d\n",res); //결과 출력
    return 0;
}
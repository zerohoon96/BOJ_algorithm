#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct block{ //block 정보를 저장 (좌표, 이전 블럭 접근 횟수, 충돌여부)
    int x,y,ct,smash;
    block(int a,int b,int c,int d){
        x=a;
        y=b;
        ct=c;
        smash=d;
    }
};
int main(void){
    vector<vector<vector<int> > > check;
    vector<vector<char> > map;
    queue<block> que; 
    int n,m,i,j,x,y,ct,smash,res=-1;
    int rotate[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    char tmp[1000];
    scanf("%d%d",&n,&m);
    map.resize(n,vector<char>(m,0));
    check.resize(n,vector<vector<int> >(m,vector<int>(2,n*m+1)));
    for(i=0;i<n;i++){
        scanf("%s",tmp);
        for(j=0;j<m;j++)
            map[i][j]=tmp[j];
    }
    que.push(block(0,0,1,0));
    while(!que.empty()){ //BFS로 진행
        x=que.front().x;
        y=que.front().y;
        ct=que.front().ct;
        smash=que.front().smash;
        que.pop();
        if(x<0||x>n-1||y<0||y>m-1) //범위를 벗어나면 continue
            continue;
        if(x==n-1&&y==m-1){ //목적지에 도달한 경우 저장 후 break
            res=ct;
            break;
        }
        if(check[x][y][smash]<=ct) //현재 블럭의 충돌상태에서 이전 기록이 더 작으면 continue
            continue;
        check[x][y][smash]=ct;
        if(map[x][y]=='1'){ //벽을 부숴야 하는 경우
            if(smash==1) //이미 벽을 부쉈으면 continue
                continue;
            smash=1;
        }
        for(i=0;i<4;i++) //4방향을 돌며 que에 push
            que.push(block(x+rotate[i][0],y+rotate[i][1],ct+1,smash));
    }
    printf("%d\n",res);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int n,m,zero_ct=0,res;
int map[8][8],direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
queue<pair<int,int> > que;
void BFS(){
    int tmp_map[8][8];
    int i,x,y,tmp_x,tmp_y,remain=zero_ct-3; //3개의 벽을 만들었기 때문에 남은 개수는 0개수 - 3
    memcpy(tmp_map,map,sizeof(int)*64);
    queue<pair<int,int> > tmp_que=que;
    while(!tmp_que.empty()){
        x=tmp_que.front().first;
        y=tmp_que.front().second;
        tmp_que.pop();
        for(i=0;i<4;i++){ //4방향 돌며 탐색
            tmp_x=x+direction[i][0];
            tmp_y=y+direction[i][1];
            if(tmp_x>n-1||tmp_x<0||tmp_y>m-1||tmp_y<0) //범위를 벗어났으면 continue
                continue;
            if(tmp_map[tmp_x][tmp_y]>0) //빈 공간이 아닌 경우 conitnue
                continue;
            tmp_map[tmp_x][tmp_y]=2; //바이러스 전파
            remain--;
            tmp_que.push(make_pair(tmp_x,tmp_y)); //큐에 삽입
        }
    }
    if(remain>res) //최댓값 판별
        res=remain;
}

void solve(int x,int y,int ct){
    int i,j;
    if(ct==3){
        BFS();
        return;
    }
    for(i=0;i<n;i++){
        if(i<x) //이전에 방문했던 곳은 방문하지 않음
            continue;
        for(j=0;j<m;j++){
            if(i==x&&j<=y)
                continue;
            if(map[i][j]!=0)
                continue;
            map[i][j]=1;
            solve(i,j,ct+1);
            map[i][j]=0;
        }
    }
}

int main(void){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==2) //바이러스면 큐에 저장
                que.push(make_pair(i,j));
            if(map[i][j]==0) //현재 0 개수 저장
                zero_ct++;
        }
    }
    solve(-1,-1,0);
    printf("%d\n",res); //정답 출력
    return 0;
}
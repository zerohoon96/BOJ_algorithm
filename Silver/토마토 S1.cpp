#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
struct tomato{ //토마토 정보를 저장
    int x,y,day;
    tomato(int a,int b,int c){
        x=a;
        y=b;
        day=c;
    }
};
int main(void){
    int n,m,i,j,x,y,day,tmp_x,tmp_y,ct=0,res=0;
    int rotate[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    queue<tomato>que;
    scanf("%d%d",&m,&n);
    vector<vector<int> > map(n,vector<int>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==1) //익은 토마토를 queue에 push
                que.push(tomato(i,j,0));
            else if(map[i][j]==0) //익지 않은 토마토의 개수 저장
                ct++;
        }
    }
    while(!que.empty()){ //BFS
        x=que.front().x;
        y=que.front().y;
        day=que.front().day;
        que.pop();
        for(i=0;i<4;i++){ //상하좌우 방향으로 탐색
            tmp_x=x+rotate[i][0];
            tmp_y=y+rotate[i][1];
            if(tmp_x<0||tmp_x>n-1||tmp_y<0||tmp_y>m-1) //범위를 벗어나면 continue
                continue;
            if(map[tmp_x][tmp_y]!=0) //1 or -1인 경우 continue
                continue;
            map[tmp_x][tmp_y]=1;
            que.push(tomato(tmp_x,tmp_y,day+1));
            ct--;
        }
        if(que.empty()) //마지막 데이터인 경우 day 저장
            res=day;
    }
    if(ct==0) //익지 않은 잔여 토마토가 없는 경우 결과 출력
        printf("%d\n",res);
    else //익지 않은 토마토가 있는 경우 -1 출력
        printf("-1\n");
    return 0;
}
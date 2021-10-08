#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
struct cheese{
    int x,y,ct;
    cheese(int a,int b,int c){
        x=a;
        y=b;
        ct=c;
    }
};
vector<vector<int> > map,tmp;
queue<cheese> que;
int n,m,i,j,x,y,ct=0,cur,tmp_x,tmp_y,tmp_ct;
int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

void BFS_1(int i,int j){ //외부 공기를 채우는 BFS
    queue<cheese> que;
    int k,x,y,tmp_x,tmp_y;
    que.push(cheese(i,j,0));
    tmp[i][j]=2;
    while(!que.empty()){
        x=que.front().x;
        y=que.front().y;
        que.pop();
        for(k=0;k<4;k++){
            tmp_x=x+direction[k][0];
            tmp_y=y+direction[k][1];
            if(tmp_x>n-1||tmp_x<0||tmp_y>m-1||tmp_y<0) //범위 검사
                continue;
            if(tmp[tmp_x][tmp_y]==0){ //외부 공기(2)나 치즈(1)인 경우에는 진행하지 않음
                que.push(cheese(tmp_x,tmp_y,0));
                tmp[tmp_x][tmp_y]=2;
            }
        }
    }
}

void BFS_2(){
    while(!que.empty()){ //BFS
        x=que.front().x;
        y=que.front().y;
        ct=que.front().ct;
        if(ct>cur){ //횟수가 늘어난 경우 업데이트
            cur++;
            map=tmp;
        }
        que.pop();
        tmp_ct=0;
        for(i=0;i<4;i++){ //4방향을 돌며 탐색
            tmp_x=x+direction[i][0];
            tmp_y=y+direction[i][1];
            if(tmp_x>n-1||tmp_x<0||tmp_y>m-1||tmp_y<0) //범위 검사
                continue;
            if(map[tmp_x][tmp_y]==2) //외부 공기인 경우 횟수 증가 (0 : 내부 공기, 1 : 치즈, 2 : 외부 공기)
                tmp_ct++;
        }
        if(tmp_ct>1) //치즈가 녹는 경우 (외부 공기 2번이상 만남)
            BFS_1(x,y);
        else
            que.push(cheese(x,y,ct+1));
    }
}
int main(void){
    scanf("%d%d",&n,&m);
    tmp.resize(n,vector<int>(m));
    for(i=0;i<n;i++){ //map 정보 입력
        for(j=0;j<m;j++){
            scanf("%d",&tmp[i][j]);
            if(tmp[i][j]==1) //치즈면 que에 push
                que.push(cheese(i,j,1));
        }
    }
    BFS_1(0,0); //첫 외부 공기 범위를 설정
    map=tmp;
    BFS_2();
    printf("%d\n",ct); //결과 출력 (큐에 한번도 안들어갔으면 ct의 초기값인 0이 출력될 것)
    return 0;
}
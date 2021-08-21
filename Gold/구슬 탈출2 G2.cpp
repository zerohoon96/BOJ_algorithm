#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
struct info{
    int r_x,r_y,b_x,b_y,direction,ct;
    info(int a,int b,int c,int d,int e,int f){
        r_x=a;
        r_y=b;
        b_x=c;
        b_y=d;
        direction=e;
        ct=f;
    }
};
int main(void){
    int i,j,n,m,res=-1;
    int r_x,r_y,b_x,b_y,tmp_x,tmp_y,r_prio_x,r_prio_y,b_prio_x,b_prio_y;
    int ct,direction;
    int rotate[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    char buf[10];
    bool r_finish,b_finish;
    vector<vector<char> > map;
    vector<vector<bool> > check;
    queue<info> que;
    scanf("%d%d",&n,&m);
    map.resize(n,vector<char>(m,0));
    check.resize(n*n,vector<bool>(m*m,false));
    for(i=0;i<n;i++){ //입력과 동시에 R, B 구슬 좌표 저장
        scanf("%s",buf);
        for(j=0;j<m;j++){
            if(buf[j]=='R'){
                r_x=i;
                r_y=j;
            }
            else if(buf[j]=='B'){
                b_x=i;
                b_y=j;
            }
            map[i][j]=buf[j];
        }
    }
    for(i=0;i<4;i++) //4방향 삽입
        que.push(info(r_x,r_y,b_x,b_y,i,0));
    while(!que.empty()){ //더이상 구슬을 움직일 수 없을 때까지 반복
        r_x=que.front().r_x;
        r_y=que.front().r_y;
        b_x=que.front().b_x;
        b_y=que.front().b_y;
        direction=que.front().direction;
        ct=que.front().ct;
        que.pop();
        r_finish=b_finish=false;
        for(i=0;i<10;i++){ //R 구슬 이동
            tmp_x=r_x+rotate[direction][0];
            tmp_y=r_y+rotate[direction][1];
            if(map[tmp_x][tmp_y]=='#') //벽에 도달한 경우 break
                break;
            else if(map[tmp_x][tmp_y]=='O'){ //구멍에 들어간 경우 표시 후 break
                r_finish=true;
                break;
            }
            else{ //좌표, 임시좌표 업데이트
                r_prio_x=r_x;
                r_prio_y=r_y;
                r_x=tmp_x;
                r_y=tmp_y;
            }
        }
        for(j=0;j<10;j++){ //B 구슬 이동
            tmp_x=b_x+rotate[direction][0];
            tmp_y=b_y+rotate[direction][1];
            if(map[tmp_x][tmp_y]=='#') //벽에 도달한 경우 break
                break;
            else if(map[tmp_x][tmp_y]=='O'){ //구멍에 들어간 경우 표시 후 break
                b_finish=true;
                break;
            }
            else{ //좌표, 임시좌표 업데이트
                b_prio_x=b_x;
                b_prio_y=b_y;
                b_x=tmp_x;
                b_y=tmp_y;
            }
        }
        if(r_finish||b_finish){ //구멍에 들어간 구슬이 있는 경우
            if(b_finish)
                continue;
            res=ct+1; //R 구슬만 구멍에 들어갔으면 break
            break;
        }
        if(ct+1==10) //10번을 이동했는데 실패했으면 진행하지 않고 continue
            continue;
        if(r_x==b_x&&r_y==b_y){ //같은 칸에 있는 경우
            if(i<j){ //R이 더 먼저 도착
                b_x=b_prio_x;
                b_y=b_prio_y;
            }
            else{ //B가 더 먼저 도착
                r_x=r_prio_x;
                r_y=r_prio_y;
            }
        }
        if(check[r_x*n+b_x][r_y*m+b_y]) //새로운 R 구슬 위치 , B 구슬 위치로 이미 방문한 경우 continue
            continue;
        check[r_x*n+b_x][r_y*m+b_y]=true;
        for(i=0;i<4;i++){
            if((direction==0&&i==1)||(direction==1&&i==0)||(direction==2&&i==3)||(direction==3&&i==2)) //왔던 방향으로 돌아가지 않음
                continue;
            que.push(info(r_x,r_y,b_x,b_y,i,ct+1));
        }
    }
    printf("%d\n",res);
    return 0;
}
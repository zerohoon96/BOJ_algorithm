#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct info{
    int x,y,ct;
    info(int a,int b,int c){
        x=a;
        y=b;
        ct=c;
    }
};
int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int r,c,water_ct=0;
vector<vector<char> > map;
vector<vector<bool> > check;
queue<info> water_que;
void update_water(){ //물의 위치를 업데이트하는 함수
    int i,x,y,tmp_x,tmp_y,ct;
    while(!water_que.empty()){
        x=water_que.front().x;
        y=water_que.front().y;
        ct=water_que.front().ct;
        if(ct==water_ct) //물 위치 업데이트가 끝난 경우 종료
            break;
        water_que.pop();
        for(i=0;i<4;i++){ //4방향을 돌며 물 위치 업데이트
            tmp_x=x+direction[i][0];
            tmp_y=y+direction[i][1];
            if(tmp_x>r-1||tmp_x<0||tmp_y>c-1||tmp_y<0) //범위를 벗어났으면 X
                continue;
            if(map[tmp_x][tmp_y]=='*'||map[tmp_x][tmp_y]=='X'||map[tmp_x][tmp_y]=='D') //물 or 바위 or 비버의굴이면 X
                continue;
            map[tmp_x][tmp_y]='*';
            water_que.push(info(tmp_x,tmp_y,ct+1));
        }
    }
}

int main(void){
    int i,j,x,y,tmp_x,tmp_y,ct;
    char buf[50];
    queue<info> que;
    pair<int,int> dest;
    scanf("%d%d",&r,&c);
    map.resize(r,vector<char>(c));
    check.resize(r,vector<bool>(c,false));
    for(i=0;i<r;i++){ //현재 상태를 입력받음
        scanf("%s",buf);
        for(j=0;j<c;j++){
            map[i][j]=buf[j];
            if(map[i][j]=='S'){ //고슴도치 위치
                que.push(info(i,j,0));
                check[i][j]=true;
            }
            else if(map[i][j]=='D') //비버의 굴 위치
                dest=make_pair(i,j);
            else if(map[i][j]=='*') //물 위치
                water_que.push(info(i,j,0));
        }
    }

    while(!que.empty()){
        x=que.front().x;
        y=que.front().y;
        ct=que.front().ct;
        if(ct==water_ct){ //물 위치를 업데이트할 순서에 업데이트
            water_ct++;
            update_water();
        }
        que.pop();
        for(i=0;i<4;i++){
            tmp_x=x+direction[i][0];
            tmp_y=y+direction[i][1];
            if(tmp_x==dest.first&&tmp_y==dest.second){ //종료조건 검사
                printf("%d\n",ct+1);
                return 0;
            }
            if(tmp_x>r-1||tmp_x<0||tmp_y>c-1||tmp_y<0) //범위를 벗어났으면 X
                continue;
            if(check[tmp_x][tmp_y]) //이미 방문했으면 X
                continue;
            if(map[tmp_x][tmp_y]=='*'||map[tmp_x][tmp_y]=='X') //물이거나 바위인 경우 X
                continue;
            check[tmp_x][tmp_y]=true;
            que.push(info(tmp_x,tmp_y,ct+1));
        }
    }
    printf("KAKTUS\n");
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
queue<pair<int,int> > que;
int r,c,t;
int air_x=-1;
int map[50][50],tmp_map[50][50];
int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

void move_dust(){ //미세먼지 확산 함수
    int i,j,x,y,tmp_x,tmp_y,tmp_ct;
    memset(tmp_map,0,sizeof(int)*50*50);
    while(!que.empty()){
        x=que.front().first;
        y=que.front().second;
        que.pop();
        tmp_ct=0;
        for(i=0;i<4;i++){ //4방향을 돌며 탐색
            tmp_x=x+direction[i][0];
            tmp_y=y+direction[i][1];
            if(tmp_x>r-1||tmp_x<0||tmp_y>c-1||tmp_y<0) //범위 검사
                continue;
            if(map[tmp_x][tmp_y]<0) //공기청정기 칸이면 안됨
                continue;
            tmp_ct++;
            tmp_map[tmp_x][tmp_y]+=map[x][y]/5; //새로운 미세먼지값 설정
        }
        map[x][y]-=map[x][y]/5*tmp_ct; //공식에 따라 값 설정
    }
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            map[i][j]+=tmp_map[i][j];
}

void operate_machine(){ //공기청정기 가동 함수
    int i;
    //윗부분 공기청정기 가동
    for(i=air_x-1;i>0;i--)
        map[i][0]=map[i-1][0];
    for(i=0;i<c-1;i++)
        map[0][i]=map[0][i+1];
    for(i=0;i<air_x;i++)
        map[i][c-1]=map[i+1][c-1];
    for(i=c-1;i>1;i--)
        map[air_x][i]=map[air_x][i-1];
    map[air_x][1]=0;

    //아랫부분 공기청정기 가동
    for(i=air_x+2;i<r-1;i++)
        map[i][0]=map[i+1][0];
    for(i=0;i<c-1;i++)
        map[r-1][i]=map[r-1][i+1];
    for(i=r-1;i>air_x+1;i--)
        map[i][c-1]=map[i-1][c-1];
    for(i=c-1;i>1;i--)
        map[air_x+1][i]=map[air_x+1][i-1];
    map[air_x+1][1]=0;
}

void find_dust(){ //미세먼지 큐 생성 함수
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(map[i][j]>0)
                que.push(make_pair(i,j));
        }
    }
}
int main(void){
    int i,j,res=0;
    scanf("%d%d%d",&r,&c,&t);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]<0){
                if(air_x>=0)
                    continue;
                air_x=i;                
            }
            if(map[i][j]>0)
                que.push(make_pair(i,j));
        }
    }
    for(i=0;i<t;i++){ //t초동안 반복
        //1. 미세먼지 확산
        move_dust();
        //2. 공기청정기 가동
        operate_machine();
        //3. 미세먼지 큐 만들기
        find_dust();
    }
    
    while(!que.empty()){ //큐에 있는 모든 미세먼지 꺼내서 더하기
        res+=map[que.front().first][que.front().second];
        que.pop();
    }
    printf("%d\n",res);
    return 0;
}
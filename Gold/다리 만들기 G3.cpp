#include <stdio.h>
#include <string.h>
#include <queue>
#define MAX 2147000000
using namespace std;
struct info{
    int x,y,ct;
    info(int a,int b,int c){
        x=a;
        y=b;
        ct=c;
    }
};
int n,island=2;
int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int map[100][100],check[100][100];
queue<info> que;
void DFS(int x,int y){ //DFS
    int i,tmp_x,tmp_y;
    map[x][y]=island;
    que.push(info(x,y,0));
    for(i=0;i<4;i++){
        tmp_x=x+direction[i][0];
        tmp_y=y+direction[i][1];
        if(tmp_x<0||tmp_x>n-1||tmp_y<0||tmp_y>n-1)
            continue;
        if(map[tmp_x][tmp_y]!=1)
            continue;
        DFS(tmp_x,tmp_y);
    }
}
int main(void){
    int i,j;
    int x,y,ct,tmp_x,tmp_y,res=MAX;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%d",&map[i][j]);
    }
    for(i=0;i<n;i++){ //DFS로 섬 번호 저장하기
        for(j=0;j<n;j++){
            if(map[i][j]!=1) //육지가 아니거나 이미 다른 섬인 경우 continue
                continue;
            DFS(i,j);
            island++; //섬 번호 업데이트
        }
    }
    while(!que.empty()){
        x=que.front().x;
        y=que.front().y;
        island=map[x][y];
        memset(check,0,sizeof(int)*100*100);
        queue<info> tmp_que;
        while(!que.empty()){ //한 섬의 육지들을 tmp_que에 저장
            x=que.front().x;
            y=que.front().y;
            if(map[x][y]!=island)
                break;
            check[x][y]=true;
            tmp_que.push(que.front());
            que.pop();
        }
        while(!tmp_que.empty()){ //BFS
            x=tmp_que.front().x;
            y=tmp_que.front().y;
            ct=tmp_que.front().ct;
            if(ct>=res) //현재까지 결과보다 길어지면 break
                break;
            tmp_que.pop();
            for(i=0;i<4;i++){
                tmp_x=x+direction[i][0];
                tmp_y=y+direction[i][1];
                if(tmp_x<0||tmp_x>n-1||tmp_y<0||tmp_y>n-1) //범위를 벗어나면 continue
                    continue;
                if(check[tmp_x][tmp_y]) //이미 방문했으면 continue
                    continue;
                if(map[tmp_x][tmp_y]>1){ //다른 섬이면 정답 검사 후 break
                    if(ct<res)
                        res=ct;
                    break;
                }
                tmp_que.push(info(tmp_x,tmp_y,ct+1));
                check[tmp_x][tmp_y]=true;
            }
            if(i<4)
                break;
        }
    }
    if(res==MAX) //정답이 업데이트 되지 않았으면 0으로 설정
        res=0;
    printf("%d\n",res);
    return 0;
}
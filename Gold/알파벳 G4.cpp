#include <stdio.h>
int r,c,res=1;
int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int map[20][20];
bool check[26];
void DFS(int x,int y,int ct){
    int i,tmp_x,tmp_y;
    for(i=0;i<4;i++){ //4방향을 돌면서 탐색 (이미 거친 자리는 어차피 알파벳 체크에서 걸러질 것)
        tmp_x=x+direction[i][0];
        tmp_y=y+direction[i][1];
        if(tmp_x>r-1||tmp_x<0||tmp_y>c-1||tmp_y<0) //map 범위를 벗어났으면 continue
            continue;
        if(check[map[tmp_x][tmp_y]]){ //이미 탐색한 알파벳인 경우 정답 체크 후 continue
            if(ct>res)
                res=ct;
            continue;
        }
        check[map[tmp_x][tmp_y]]=true;
        DFS(tmp_x,tmp_y,ct+1);
        check[map[tmp_x][tmp_y]]=false;
    }
}
int main(void){
    int i,j;
    char buf[20];
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++){ //map에 알파벳 배치 상태 저장
        scanf("%s",buf);
        for(j=0;j<c;j++)
            map[i][j]=buf[j]-65;
    }
    check[map[0][0]]=true; //첫 알파벳 방문 처리
    DFS(0,0,1); //DFS 실행
    printf("%d\n",res);
    return 0;
}
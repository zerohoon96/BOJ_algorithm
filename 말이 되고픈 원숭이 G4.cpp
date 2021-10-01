#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
struct info{ //정보 저장 구조체
    int x,y,ct,k_ct;
    info(int a,int b,int c,int d){
        x=a;
        y=b;
        ct=c;
        k_ct=d;
    }
};
int main(void){
    int k,n,m,i,j;
    int x,y,ct,k_ct,tmp_x,tmp_y;
    int direction[12][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{1,2},{2,1},{1,0},{-1,0},{0,-1},{0,1}};
    queue<info> que;
    vector<vector<int> > map,check;
    
    scanf("%d%d%d",&k,&m,&n);
    map.resize(n,vector<int>(m));
    check.resize(n,vector<int>(m,k+1)); //칸별로 몇 번의 k 이동을 했는지 저장하는 백터
    que.push(info(0,0,0,0));
    check[0][0]=0;
    for(i=0;i<n;i++) //map 정보 입력
        for(j=0;j<m;j++)
            scanf("%d",&map[i][j]);

    while(!que.empty()){ //BFS
        x=que.front().x;
        y=que.front().y;
        ct=que.front().ct;
        k_ct=que.front().k_ct;
        if(x==n-1&&y==m-1)
            break;
        que.pop();
        if(k_ct<k){ //아직 k번만큼 말처럼 움직이지 않은 경우 말처럼 이동
            for(i=0;i<8;i++){
                tmp_x=x+direction[i][0];
                tmp_y=y+direction[i][1];
                if(tmp_x>n-1||tmp_x<0||tmp_y>m-1||tmp_y<0)
                    continue;
                if(map[tmp_x][tmp_y]||check[tmp_x][tmp_y]<=k_ct+1)
                    continue;
                check[tmp_x][tmp_y]=k_ct+1;
                que.push(info(tmp_x,tmp_y,ct+1,k_ct+1));
            }
        }
        for(i=8;i<12;i++){
            tmp_x=x+direction[i][0];
            tmp_y=y+direction[i][1];
            if(tmp_x>n-1||tmp_x<0||tmp_y>m-1||tmp_y<0||map[tmp_x][tmp_y]||check[tmp_x][tmp_y]<=k_ct) //조건 검사
                continue;
            check[tmp_x][tmp_y]=k_ct;
            que.push(info(tmp_x,tmp_y,ct+1,k_ct));
        }
    }
    if(!que.empty())
        printf("%d\n",ct);
    else
        printf("-1\n");
    return 0;
}
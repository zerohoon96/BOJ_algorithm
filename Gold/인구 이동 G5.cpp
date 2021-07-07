#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
struct info{ //국가 정보를 저장하는 구조체 (좌표, 병합 횟수, 총합) (병합 횟수, 총합은 최고 노드에만 기록됨)
    int x,y,ct,sum;
    info(int a,int b,int c,int d){
        x=a;
        y=b;
        ct=c;
        sum=d;
    }
};
vector<vector<int> > map;
vector<vector<info> > vec;
info Find(int x,int y){ //Find 함수
    if(x==vec[x][y].x&&y==vec[x][y].y)
        return vec[x][y];
    return vec[x][y]=Find(vec[x][y].x,vec[x][y].y);
}
void Union(info n1,info n2){ //Union 함수
    n1=Find(n1.x,n1.y);
    n2=Find(n2.x,n2.y);
    if(n1.x==n2.x&&n1.y==n2.y) //Find로 저장한 두 구조체가 동일하면 리턴 (이미 둘다 더해짐)
        return;
    vec[n2.x][n2.y].x=n1.x;
    vec[n2.x][n2.y].y=n1.y;
    vec[n1.x][n1.y].ct+=n2.ct;
    vec[n1.x][n1.y].sum+=n2.sum;
    vec[n2.x][n2.y].ct=0; //병합이 완료된 경우 0으로 저장
    vec[n2.x][n2.y].sum=0;
}
int main(void){
    int n,L,R,i,j,diff,res=0;
    bool success;
    scanf("%d%d%d",&n,&L,&R);
    map.resize(n,vector<int>(n));

    for(i=0;i<n;i++){ //데이터 입력
        for(j=0;j<n;j++)
            scanf("%d",&map[i][j]);
    }

    while(1){
        success=false;
        vec.resize(n,vector<info>(n,info(0,0,0,0)));
        for(i=0;i<n;i++) //vec 백터 초기화
            for(j=0;j<n;j++)
                vec[i][j]=info(i,j,1,map[i][j]);
        for(i=0;i<n;i++){ //모든 국가의 국경을 검사
            for(j=0;j<n;j++){
                if(i+1<n){ // → 방향 국경 검사
                    diff=abs(map[i][j]-map[i+1][j]);
                    if(diff>=L&&diff<=R){ //국경을 합칠 수 있는 경우 Union
                        Union(vec[i][j],vec[i+1][j]);
                    }
                }
                if(j+1<n){ // ↓ 방향 국경 검사
                    diff=abs(map[i][j]-map[i][j+1]);
                    if(diff>=L&&diff<=R){ //국경을 합칠 수 있는 경우 Union
                        Union(vec[i][j],vec[i][j+1]);
                    }
                }
            }
        }
        for(i=0;i<n;i++){ //인구 이동
            for(j=0;j<n;j++){
                struct info tmp=Find(i,j);
                if(tmp.ct==1) //국경이 한 번도 뚫리지 않은 국가는 continue
                    continue;
                success=true; //인구 이동 기록
                map[i][j]=tmp.sum/tmp.ct;
            }
        }
        if(success)
            res++;
        else //인구 이동을 하지 않았으면 종료
            break;
    }
    printf("%d\n",res);
    return 0;
}
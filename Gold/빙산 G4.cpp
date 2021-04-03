#include <stdio.h>
#include <vector>
using namespace std;
struct info{
	int x,y,val;
	info(int a,int b,int c){
		x=a;
		y=b;
		val=c;
	}
};
int n,m,ct,map[300][300],check[300][300];
int rotate[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
vector<info>sea;
void ice(int x,int y){
	int i,tmp_x,tmp_y,emp=0;
	check[x][y]=1;
	ct++;
	for(i=0;i<4;i++){ //인접 4방향 탐색
		tmp_x=x+rotate[i][0];
		tmp_y=y+rotate[i][1];
		if(tmp_x<0||tmp_x>n-1||tmp_y<0||tmp_y>m-1) //범위를 벗어남 
			continue;
		if(map[tmp_x][tmp_y]<1){ //빙산이 없는 공간인 경우 
			emp++;
			continue;
		}
		if(check[tmp_x][tmp_y]!=0) //이미 방문한 노드 
			continue;
		ice(tmp_x,tmp_y); //재귀호출 
	}
	sea.push_back(info(x,y,emp)); //좌표, 뺄 수를 구조체로 저장 
}
int main(void){
	int i,j,x,y,res=0,mt=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]>0){ //현재 산 개수를 저장 
				mt++;
				if(sea.empty())
					sea.push_back(info(i,j,1));
			}
		}
	}
	while(1){
		if(mt<=1){ //더이상 2개로 쪼갤 수 없음 (없거나, 1개 남은 경우) 
			res=0;
			break;
		}
		for(i=0;i<(int)sea.size();i++) //첫 빙산 위치 저장
			if(map[sea[i].x][sea[i].y]>0)
				break;
		x=sea[i].x;
		y=sea[i].y;
		sea.clear();
		ct=0;
		ice(x,y);
		if(ct<mt) //덩어리가 두개 이상인 경우 종료 (끊어지지 않을때까지 탐색했는데 전부 탐색하지 못함) 
			break;
		for(i=0;i<(int)sea.size();i++){ //저장된 정보를 바탕으로 연산 수행 
			x=sea[i].x;
			y=sea[i].y;
			map[x][y]-=sea[i].val;
			if(map[x][y]<1)
				mt--; 
			check[x][y]=0; //체크배열 복구 
		}
		res++; //1년 증가
	}
	printf("%d\n",res);
	return 0;
}

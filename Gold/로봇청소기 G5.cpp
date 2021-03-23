#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int i,j,n,m,r,c,dir,ct=0;
	int tmp_r,tmp_c,tmp_dir;
	int info[4][2]={{-1,0},{0,1},{1,0},{0,-1}}; //북,동,남,서 순으로 정보 저장 
	scanf("%d%d",&n,&m);
	vector<vector<int> >map(n+2,vector<int>(m+2,1));
	scanf("%d%d%d",&r,&c,&dir);
	r++;
	c++;
	for(i=1;i<=n;i++) //장소 상태 입력 
		for(j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	while(1){
		if(map[r][c]==0){ //청소되어 있지 않으면 청소 (2로 표시) 
			map[r][c]=2;
			ct++;
		}
		tmp_dir=dir;
		for(i=0;i<4;i++){ //방향을 바꾸며 검사 
			tmp_dir--; //왼쪽으로 방향 업데이트 
			if(tmp_dir<0)
				tmp_dir=3;
			tmp_r=r+info[tmp_dir][0];
			tmp_c=c+info[tmp_dir][1];
			if(map[tmp_r][tmp_c]==0){ //현재 방향에서 한칸 전진했을때 청소 안된 칸 발견한 경우 전진
				r=tmp_r;
				c=tmp_c;
				dir=tmp_dir;
				break;
			}
		}
		if(i<4) //다음 칸으로 전진 
			continue;
		else{ //전진 불가능->후진 시도 
			r-=info[dir][0];
			c-=info[dir][1];
			if(map[r][c]==1) //후진도 불가능하면 작동 중지 
				break;
		}
	}
	printf("%d\n",ct); //답 출력 
	return 0;
}

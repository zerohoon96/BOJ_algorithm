#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
struct info{ //드레곤 커브의 선분을 저장하는 구조체 
	int x,y,d;
	info(int a,int b,int c){
		x=a;
		y=b;
		d=c;
	}
};
int main(void){
	int n,x,y,d,g,tmp_x,tmp_y,i,j,k,res=0;
	int rotate[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
	bool map[101][101];
	memset(map,false,sizeof(bool)*101*101);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		vector<info> dragon_curve;
		scanf("%d%d%d%d",&x,&y,&d,&g);
		map[x][y]=true;
		x+=rotate[d][0];
		y+=rotate[d][1];
		d-=2;
		if(d==-1)
			d=3;
		else if(d==-2)
			d=2;
		dragon_curve.push_back(info(x,y,d));
		map[x][y]=true;
		for(j=1;j<=g;j++){ //1세대 ~ 마지막 세대까지 실행
			tmp_x=dragon_curve.back().x; //끝점 저장 
			tmp_y=dragon_curve.back().y;
			for(k=(int)dragon_curve.size()-1;k>=0;k--){ //이전 드레곤 커브 정보를 바탕으로 새로운 드래곤커브 생성 
				d=dragon_curve[k].d-1; //현재 선분의 방향을 90도 회전
				if(d<0)
					d=3;
				tmp_x+=rotate[d][0]; //새로 도달한 좌표 저장 후 map에 표시 
				tmp_y+=rotate[d][1]; 
				map[tmp_x][tmp_y]=true;
				d-=2; //방향 수정 
				if(d==-1)
					d=3;
				else if(d==-2)
					d=2;
				dragon_curve.push_back(info(tmp_x,tmp_y,d)); //선분을 추가 
			}
		}
	}
	for(i=0;i<100;i++){ //사각형 개수 구하기 
		for(j=0;j<100;j++){
			if(!map[i][j])
				continue;
			if(!map[i+1][j]||!map[i][j+1]||!map[i+1][j+1])
				continue;
			res++;
		}
	}
	printf("%d\n",res);
	return 0;
}

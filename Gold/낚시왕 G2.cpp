#include <stdio.h>
#include <vector>
using namespace std;
struct shark{ //상어 정보를 저장하는 구조체 
	int s,d,z;
	shark(){}
	shark(int a,int b,int c){
		s=a;
		d=b;
		z=c;
	}
};
int main(void){
	int i,j,r,c,n,x,y,s,d,z,diff,cur=0,res=0;
	int n1,n2,n3,n4,n5;
	int rotate[5][2]={{},{-1,0},{1,0},{0,1},{0,-1}}; 
	scanf("%d%d%d",&r,&c,&n);
	vector<vector<shark> > map(r,vector<shark>(c));
	vector<pair<int,int> > info;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			map[i][j]=shark(0,0,0);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5);
		map[n1-1][n2-1]=shark(n3,n4,n5);
		info.push_back(make_pair(n1-1,n2-1));
	}
	while(cur<c){ //가장 오른쪽으로 이동할 때까지 반복
		vector<vector<shark> > tmp_map(r,vector<shark>(c));
		vector<pair<int,int> > tmp_info;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				tmp_map[i][j]=shark(0,0,0);
				
		for(i=0;i<r;i++){ //낚시꾼이 잡는 상어 탐색 
			if(map[i][cur].z>0){
				res+=map[i][cur].z;
				map[i][cur].z=0;
				break;
			}
		}
		
		for(i=0;i<(int)info.size();i++){ //현재 상어들의 위치를 이동 
			x=info[i].first;
			y=info[i].second;
			if(map[x][y].z<=0) //유효하지 않은 상어면 다음 상어로 (이미 잡은 상어)  
				continue;
			s=map[x][y].s;
			d=map[x][y].d;
			z=map[x][y].z;
			x+=rotate[d][0]*s; //현재 상어의 속도에 따라 새로운 위치값 저장 
			y+=rotate[d][1]*s;
			if(x<0||x>r-1){ //x가 범위를 넘어간 경우 
				if(x<0){ //넘어간 정도를 계산 
					diff=x*-1;
					d=2;
				}
				else{
					diff=x-(r-1);
					d=1;
				}
				if(diff/(r-1)>0){ //넘어간 정도에 따라서 방향, 새로운 위치 저장 
					if(diff/(r-1)%2==1){
						if(d==1)
							d=2;
						else
							d=1;
					}
					diff%=r-1;
				}
				if(d==1)
					x=r-1-diff;
				else
					x=diff;
			}
			if(y<0||y>c-1){ //y가 범위를 넘어간 경우 
				if(y<0){ //넘어간 정도를 계산 
					diff=y*-1;
					d=3;
				}
				else{
					diff=y-(c-1);
					d=4;
				}
				if(diff/(c-1)>0){ //넘어간 정도에 따라서 방향, 새로운 위치 저장 
					if(diff/(c-1)%2==1){
						if(d==3)
							d=4;
						else
							d=3;
					}
					diff%=c-1;
				}
				if(d==4)
					y=c-1-diff;
				else
					y=diff;
			}
			if(tmp_map[x][y].z<=0){ //아무도 없는 경우 새로 정보 저장 
				tmp_info.push_back(make_pair(x,y));
				tmp_map[x][y]=shark(s,d,z);
			}
			else if(tmp_map[x][y].z<z){ //이동하려는 칸에 크기가 작은 상어가 있는 경우 먹음
				tmp_map[x][y]=shark(s,d,z);
			}
			else //이동하려는 칸에 크기가 큰 상어가 있는 경우 먹힘 
				continue;
		} 
		map=tmp_map; //임시 정보 덮어쓰기 
		info=tmp_info;
		cur++; //낚시꾼 위치 이동
	}
	printf("%d\n",res); //정답 출력 
	return 0;
}

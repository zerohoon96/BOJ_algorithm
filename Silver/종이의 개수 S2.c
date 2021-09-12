#include <stdio.h>
#include <stdlib.h>
//#include <vector>
//using namespace std;
int **map;
int ct[3];
//vector<vector<int> > map;
void paper(int x,int y,int size){
	int i,j;
	int fail=0;
	for(i=x;i<x+size;i++){
		for(j=y;j<y+size;j++){
			if(map[i][j]!=map[x][y]){ //현재 종이가 모두 같지 않은 경우
				fail=1;
				break;
			}
		}
		if(fail){ //숫자가 다르므로 더이상 진행하지 않음
			break;
		}
	}

	if(fail){ //9등분 해서 새로운 종이 사용
		for(i=x;i<x+size;i+=size/3){
			for(j=y;j<y+size;j+=size/3){
				paper(i,j,size/3);
			}
		}
	}
	else{ //현재 종이 사용
		ct[map[x][y]+1]++;
	}
}

int main(void){
	int n,i,j;
	scanf("%d",&n);
	map=(int**)malloc(sizeof(int*)*n); //메모리 동적할당
	for(i=0;i<n;i++){
		map[i]=(int*)malloc(sizeof(int)*n);
	}
	//map.resize(n,vector<int>(n));
	//
	for(i=0;i<n;i++){ //map 정보 입력
		for(j=0;j<n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	paper(0,0,n); //Divide and Conquer
	printf("%d\n%d\n%d\n",ct[0],ct[1],ct[2]); //정답 출력
	
	for(i=0;i<n;i++){ //메모리 반환
		free(map[i]);
	}
	free(map);
	return 0;
}

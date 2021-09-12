#include <stdio.h>
#include <stdlib.h>
int **map;
void quad_tree(int x,int y,int size){
	int i,j;
	int fail=0;
	for(i=x;i<x+size;i++){
		for(j=y;j<y+size;j++){
			if(map[i][j]!=map[x][y]){ //모두 같은 숫자인지 검사
				fail=1;
				break;
			}
		}
		if(fail)
			break;
	}
	if(fail){ //현재 영역의 수가 같지 않으면 4개로 나눔
		printf("(");
		for(i=x;i<x+size;i+=size/2){
			for(j=y;j<y+size;j+=size/2){
				quad_tree(i,j,size/2);
			}
		}
		printf(")");
	}
	else{ //현재 영역이 모두 같은 수인 경우
		printf("%c",map[x][y]);
	}
}
int main(void){
	int n,i,j;
	char buf[64];
	scanf("%d",&n);
	map=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		map[i]=(int*)malloc(sizeof(int)*n);
	}
	for(i=0;i<n;i++){ //map 정보 입력
		scanf("%s",buf);
		for(j=0;j<n;j++){
			map[i][j]=buf[j];
		}
	}
	quad_tree(0,0,n);
	for(i=0;i<n;i++){
		free(map[i]);
	}
	free(map);
	return 0;
}

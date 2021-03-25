#include <stdio.h>
#include <stdlib.h>
int n,**map;
long long **dp; //경로 범위 제한으로 인해 long long 자료형 사용
long long path(int i,int j){
	if(i==n-1&&j==n-1) //마지막 칸인 경우 1 리턴
		return 1;
	if(i>=n||j>=n) //범위를 벗어난 경우 0 리턴
		return 0;
	if(dp[i][j]>=0) //이미 저장된 dp값이 있으면 리턴
		return dp[i][j];
	if(map[i][j]==0) //진행이 불가능하면 0 리턴
		return dp[i][j]=0;
	return dp[i][j]=path(map[i][j]+i,j)+path(i,map[i][j]+j);
}
int main(void){
	int i,j;
	scanf("%d",&n);
	//dp,map 배열 동적할당 
	dp=(long long**)malloc(sizeof(long long*)*n);
	map=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		dp[i]=(long long*)malloc(sizeof(long long)*n);
		map[i]=(int*)malloc(sizeof(int)*n);
	}
	//map 배열 정보 입력받고 dp배열 초기화 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&map[i][j]);
			dp[i][j]=-1;
		}
	}
	//재귀함수 실행 
	printf("%lld\n",path(0,0));
	//동적할당 해제 
	for(i=0;i<n;i++){
		free(map[i]);
		free(dp[i]);
	}
	free(map);
	free(dp);
	return 0;
}

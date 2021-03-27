#include <stdio.h>
#include <stdlib.h>
int n,**wood,**dp;
int panda(int i,int j){
	int res=0;
	if(dp[i][j]>-1) //이미 dp값이 저장된 경우 dp값 리턴 
		return dp[i][j];
	if(i>0){ //↑방향 검사 
		if(wood[i-1][j]>wood[i][j]) //현재보다 큰 경우만 검사
			dp[i-1][j]=res=panda(i-1,j);
	}
	if(i<n-1){ //↓방향 검사 
		if(wood[i+1][j]>wood[i][j]){ //현재보다 큰 경우만 검사
			dp[i+1][j]=panda(i+1,j);
			if(dp[i+1][j]>res) //4방향중 최댓값 검사 
				res=dp[i+1][j];
		}
	}
	if(j>0){ //←방향 검사 
		if(wood[i][j-1]>wood[i][j]){ //현재보다 큰 경우만 검사
			if(dp[i][j-1]==-1) //dp값이 아직 채워지지 않으면 값 저장
				dp[i][j-1]=panda(i,j-1);
			if(dp[i][j-1]>res) //4방향중 최댓값 검사 
				res=dp[i][j-1];
		}
	}
	if(j<n-1){ //→방향 검사 
		if(wood[i][j+1]>wood[i][j]){ //현재보다 큰 경우만 검사
			dp[i][j+1]=panda(i,j+1);
			if(dp[i][j+1]>res) //4방향중 최댓값 검사
				res=dp[i][j+1];
		}
	}
	return dp[i][j]=res+1; //4방향중 최댓값+1 저장. 4방향 모두 실패해도 1 저장(하루는 살 수 있으므로) 
}
int main(void){
	int i,j,tmp,res=0;
	scanf("%d",&n);
	//메모리 동적할당 
	wood=(int**)malloc(sizeof(int*)*n);	
	dp=(int**)malloc(sizeof(int*)*n);	
	for(i=0;i<n;i++){
		wood[i]=(int*)malloc(sizeof(int)*n);
		dp[i]=(int*)malloc(sizeof(int)*n);
		for(j=0;j<n;j++){
			scanf("%d",&wood[i][j]);
			dp[i][j]=-1;
		}
	}
	//재귀함수를 호출하며 답 찾기 dp[i][j] : 현재 위치에서 최대한 살 수 있는 일수 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if((tmp=panda(i,j))>res)
				res=tmp;
		}
	}
	printf("%d\n",res); //답 출력
	//메모리 공간 해제 
	for(i=0;i<n;i++){
		free(wood[i]);
		free(dp[i]);
	}
	free(wood);
	free(dp);
	return 0;
}

#include <stdio.h>
int n,m;
int arr[500][500],dp[500][500];
int path(int i,int j,int prio){
	if(i<0||i>=n||j<0||j>=m) //범위를 벗어남 
		return 0;
	if(arr[i][j]>=prio) //내리막길이 아님 
		return 0;
	if(dp[i][j]>-1) //dp[i][j]에 이미 저장된 경우 해당값 리턴 
		return dp[i][j];
	return dp[i][j]=path(i-1,j,arr[i][j])+path(i+1,j,arr[i][j])+path(i,j-1,arr[i][j])+path(i,j+1,arr[i][j]); //dp값 저장 
}
int main(void){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){ //arr 배열에 데이터 저장+dp배열 초기화(-1이 아직 접근되지 않은 것) 
		for(j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
			dp[i][j]=-1;
		}
	}
	dp[n-1][m-1]=1; //목적지 dp는 1로 설정 
	path(0,0,10001); //(0,0,0)으로 호출하면 시작부터 내리막길이 아니라고 판별되므로 최댓값인 (0,0,10001)으로 호출 
	printf("%d\n",dp[0][0]);
	return 0;
}

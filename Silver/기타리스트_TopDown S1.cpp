#include <stdio.h>
int _max=-1,n,m,v[101],dp[101][1001];
void guitar(int i,int j){
	if(j<0||j>m) //범위 검사 
		return;
	if(i==n){ //마지막 단계인경우 최댓값 검사 
		if(j>_max)
			_max=j;
		return;
	}
	if(dp[i][j]==1) //이미 지나간 경우 더이상 진행x 
		return;
	dp[i][j]=1;
	guitar(i+1,j+v[i+1]); //볼륨을 더하고 진행 
	guitar(i+1,j-v[i+1]); //볼륨을 빼고 진행 
}
int main(void){
	int i,s;
	scanf("%d%d%d",&n,&s,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	guitar(0,s);
	printf("%d\n",_max); //답 출력 
	return 0;
}

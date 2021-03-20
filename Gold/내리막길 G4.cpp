#include <stdio.h>
int n,m;
int arr[500][500],dp[500][500];
int path(int i,int j,int prio){
	if(i<0||i>=n||j<0||j>=m) //������ ��� 
		return 0;
	if(arr[i][j]>=prio) //���������� �ƴ� 
		return 0;
	if(dp[i][j]>-1) //dp[i][j]�� �̹� ����� ��� �ش簪 ���� 
		return dp[i][j];
	return dp[i][j]=path(i-1,j,arr[i][j])+path(i+1,j,arr[i][j])+path(i,j-1,arr[i][j])+path(i,j+1,arr[i][j]); //dp�� ���� 
}
int main(void){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){ //arr �迭�� ������ ����+dp�迭 �ʱ�ȭ(-1�� ���� ���ٵ��� ���� ��) 
		for(j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
			dp[i][j]=-1;
		}
	}
	dp[n-1][m-1]=1; //������ dp�� 1�� ���� 
	path(0,0,10001); //(0,0,0)���� ȣ���ϸ� ���ۺ��� ���������� �ƴ϶�� �Ǻ��ǹǷ� �ִ��� (0,0,10001)���� ȣ�� 
	printf("%d\n",dp[0][0]);
	return 0;
}

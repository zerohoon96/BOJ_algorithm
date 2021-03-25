#include <stdio.h>
#include <stdlib.h>
int n,**map;
long long **dp; //��� ���� �������� ���� long long �ڷ��� ���
long long path(int i,int j){
	if(i==n-1&&j==n-1) //������ ĭ�� ��� 1 ����
		return 1;
	if(i>=n||j>=n) //������ ��� ��� 0 ����
		return 0;
	if(dp[i][j]>=0) //�̹� ����� dp���� ������ ����
		return dp[i][j];
	if(map[i][j]==0) //������ �Ұ����ϸ� 0 ����
		return dp[i][j]=0;
	return dp[i][j]=path(map[i][j]+i,j)+path(i,map[i][j]+j);
}
int main(void){
	int i,j;
	scanf("%d",&n);
	//dp,map �迭 �����Ҵ� 
	dp=(long long**)malloc(sizeof(long long*)*n);
	map=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		dp[i]=(long long*)malloc(sizeof(long long)*n);
		map[i]=(int*)malloc(sizeof(int)*n);
	}
	//map �迭 ���� �Է¹ް� dp�迭 �ʱ�ȭ 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&map[i][j]);
			dp[i][j]=-1;
		}
	}
	//����Լ� ���� 
	printf("%lld\n",path(0,0));
	//�����Ҵ� ���� 
	for(i=0;i<n;i++){
		free(map[i]);
		free(dp[i]);
	}
	free(map);
	free(dp);
	return 0;
}

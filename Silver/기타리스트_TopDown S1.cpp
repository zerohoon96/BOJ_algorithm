#include <stdio.h>
int _max=-1,n,m,v[101],dp[101][1001];
void guitar(int i,int j){
	if(j<0||j>m) //���� �˻� 
		return;
	if(i==n){ //������ �ܰ��ΰ�� �ִ� �˻� 
		if(j>_max)
			_max=j;
		return;
	}
	if(dp[i][j]==1) //�̹� ������ ��� ���̻� ����x 
		return;
	dp[i][j]=1;
	guitar(i+1,j+v[i+1]); //������ ���ϰ� ���� 
	guitar(i+1,j-v[i+1]); //������ ���� ���� 
}
int main(void){
	int i,s;
	scanf("%d%d%d",&n,&s,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	guitar(0,s);
	printf("%d\n",_max); //�� ��� 
	return 0;
}

#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,dp[1000][1000];
char arr[1000][1000];
int square(int i,int j){
	if(i>=n||j>=m) //������ ��� ��� 0 ���� 
		return 0;
	if(arr[i][j]=='0') //�ش� �ڸ��� 0�� ��� 0 ���� 
		return 0;
	if(dp[i][j]>0) //�̹� dp���� �����ϴ� ��� �ش簪 ���� 
		return dp[i][j];
	return dp[i][j]=min(square(i+1,j),min(square(i+1,j+1),square(i,j+1)))+1; //dp�� ���ο� �� ���� (�� �������� ����� ���� dp���� �����) 
}
int main(void){
	int i,j,tmp,res=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%s",arr[i]);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(arr[i][j]=='1'){ //1�� ��쿡�� �Լ� ȣ��
				tmp=square(i,j);
				if(res<tmp) //�ִ� �Ǻ�
					res=tmp;
			}
		}
	}
	printf("%d\n",res*res);
	return 0;
}

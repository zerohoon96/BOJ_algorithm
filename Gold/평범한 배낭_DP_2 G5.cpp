#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	vector<int> weigh(n+1),value(n+1),dp(k+1);
	for(i=1;i<=n;i++)
		scanf("%d%d",&weigh[i],&value[i]);
		
	for(i=1;i<=n;i++){ //�ܰ躰�� ���� 
		for(j=k;j>0;j--){ //�� �ܰ迡�� ������ ����(0~k)�� ���� �ִ밡ġ�� ������Ʈ 
			if(j-weigh[i]>=0) //���� �ܰ� ���� ���� �� �ִ� ��쿡 ������Ʈ. ���� �� ������ ���� ���� �״�� ��� 
				dp[j]=max(dp[j-weigh[i]]+value[i],dp[j]);
		}
	}
	printf("%d\n",dp[k]);
	return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j;
	scanf("%d",&n);
	vector<int> arr(n);
	vector<long long> dp(21); 
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	dp[arr[0]]=1; //�ʱⰪ ���� 
	for(i=1;i<n-1;i++){ //ó��(�ʱⰪ), ������(��ǥ��)�� ������ �Է°� Ž�� 
		vector<long long> tmp(21);
		for(j=0;j<21;j++){ //�� �ܰ� ���ڸ� ����(+,-)������ 0~20�� ������ ����� �� ���� 
			if(j-arr[i]>=0)
				tmp[j]+=dp[j-arr[i]]; 
			if(j+arr[i]<=20)
				tmp[j]+=dp[j+arr[i]];
		}
		dp=tmp; //dp ������Ʈ 
	}
	printf("%lld\n",dp[arr[n-1]]); //���� ��� 
	return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j,data,res=0;
	scanf("%d",&n);
	vector<int> arr(n),dp(n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=n-1;i>=0;i--){
		data=0;
		for(j=n-1;j>i;j--){ //���� ���߿��� ������ dp�� ���� 
			if(arr[j]<arr[i]&&dp[j]>data)
				data=dp[j];
		}
		dp[i]=data+1; //���ο� dp�� ���� 
		if(dp[i]>res) //�ִ� �˻� 
			res=dp[i];
	}
	printf("%d\n",res);
	return 0;
} 

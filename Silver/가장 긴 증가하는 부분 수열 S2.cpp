#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j,tmp,res=-1;
	scanf("%d",&n);
	vector<int> arr(n),dp(n); //�� ���� ����, dp�� ���� ���� 
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		tmp=-1;
		for(j=0;j<i;j++){ //���������� �Էµ� ���簪���� �����鼭 dp���� �ִ��� �� ���ϱ� 
			if(arr[j]<arr[i]){
				if(dp[j]>tmp)
					tmp=dp[j];
			}
		}
		if(tmp<0) //���� ������ �Էµ� ���簪���� ��� ū ��� 1 ���� 
			dp[i]=1;
		else //�ִ񰪿� 1 ���ؼ� ���ο� dp�� ���� 
			dp[i]=tmp+1;
		if(dp[i]>res) //���� �� �����ϴ� �κм��� Ž�� 
			res=dp[i];
	}
	printf("%d\n",res); //����� ��� 
	return 0;
}

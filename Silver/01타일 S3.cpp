#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,n1,n2;
	scanf("%d",&n);
	vector<int> arr(n+1);
	arr[1]=1;
	arr[2]=2;
	
	for(i=3;i<=n;i++){
		n1=i-1; //1�� �����ϴ� ��� ���� ���� 
		n2=i-2; //00���� �����ϴ� ��� ���� ���� 
		arr[i]=(arr[n1]+arr[n2])%15746; //�����÷� ���� ���� ������ ���� 
	}
	printf("%d\n",arr[n]);
	return 0;
}

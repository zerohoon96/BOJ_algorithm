#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,R,G,B,tmp;
	scanf("%d",&n);
	vector<vector<int> > arr(n,vector<int>(3));
	scanf("%d%d%d",&arr[0][0],&arr[0][1],&arr[0][2]); //ù R,G,B�� ���� 
	for(i=1;i<n;i++){ //ĥ�Ϸ��� ���� ��ġ�� �ʴ� �� �߿� �ּڰ��� �����ؼ� ���� ĥ��(����)  
		scanf("%d%d%d",&R,&G,&B);
		arr[i][0]=R+min(arr[i-1][1],arr[i-1][2]); //R�� ���� �� ���� 
		arr[i][1]=G+min(arr[i-1][0],arr[i-1][2]); //G�� ���� �� ���� 
		arr[i][2]=B+min(arr[i-1][0],arr[i-1][1]); //B�� ���� �� ����
	}
	printf("%d\n",min(min(arr[n-1][0],arr[n-1][1]),arr[n-1][2])); //�������� �ּҰ� ��� 
	return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int m,n,i,j,n1,n2,n3,val=1;
	//freopen("input.txt","r",stdin); 
	scanf("%d%d",&m,&n);
	vector<int> arr(2*m-1); //������ ���� 
	for(i=0;i<n;i++){ //n���� �� ó��. �������� �����̹Ƿ� �������� ���� ã�Ƽ� ���尪 ���� 
		scanf("%d%d%d",&n1,&n2,&n3);
		if(n1<2*m-1&&n2>0) //���� ����� �ʰ� 1 ������ 0 �ƴϸ� ���尪 1 ���� 
			arr[n1]++;
		if(n1+n2<2*m-1){ //���� ����� ������ 2 ���� ���� 
			if(n2>0)
				arr[n1+n2]++; //1 ������ 0 �ƴϸ� 1 ���� (�̹� 1 ���忡�� 1 ���������Ƿ�) 
			else
				arr[n1+n2]+=2; //1 ������ 0�̸� 2 ���� (1 ���忡�� �������� �ʾ����Ƿ�) 
		}
	}
	for(i=0;i<2*m-1;i++){ //������ ���� ����ؼ� �迭 �ϼ� 
		if(arr[i]==0) //������ ������ ������ ���� 
			arr[i]=val;
		else{ //������ ������Ʈ 
			val+=arr[i];
			arr[i]=val;
		}
	} 
	for(i=m-1;i>=0;i--){ //��� ���. �Ųٷ� ����������Ƿ� m-1���� 0���� �ݺ� 
		printf("%d ",arr[i]);
		for(j=m;j<2*m-1;j++)
			printf("%d ",arr[j]);
		puts("");
	}
	return 0;
}

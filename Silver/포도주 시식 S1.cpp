#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(void){
	int i,n,data,arr[3],tmp[3];
	scanf("%d",&n);
	//1ȸ ������ ���� 
	arr[0]=0;
	arr[2]=-1;
	scanf("%d",&arr[1]);
	
	for(i=1;i<n;i++){ //n-1�� �ݺ�. �������� ���� Ƚ��(0~2)�� ���� �ִ��� ���� 
		scanf("%d",&data); 
		memcpy(tmp,arr,sizeof(int)*3);
		//0�� �������� ���ð� �� ��� ó�� 
		arr[1]=tmp[0]+data;
		
		//1�� �������� ���ð� �� ��� ó��		
		arr[0]=max(arr[0],tmp[1]);
		arr[2]=tmp[1]+data;
		
		//2�� �������� ���ð� �� ��� ó��
		if(tmp[2]>0)
			arr[0]=max(arr[0],tmp[2]);
	}
	printf("%d\n",max(arr[0],max(arr[1],arr[2]))); //�ִ� ��� 
	return 0;
}

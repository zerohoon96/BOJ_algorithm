#include <stdio.h>
#include <math.h>
int n,res=0;
int arr[15];
void find(int cur){
	int i,j;
	if(cur==n){ //���� �߰��� ��� 
		res++;
		return;
	}
	for(i=0;i<n;i++){ //�� ��ȣ�� �����ϸ� ã�� 
		for(j=0;j<cur;j++){
			if(i==arr[j]) //���� �� 
				break;
			if(abs(i-arr[j])==cur-j) //�밢�� ��ħ 
				break;
		}
		if(j<cur) //���� ���� x 
			continue;
		arr[cur]=i;
		find(cur+1); 
		arr[cur]=0;
	}
}
int main(void){
	scanf("%d",&n);
	find(0);
	printf("%d\n",res);
	return 0;
}

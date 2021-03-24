#include <stdio.h>
#include <string.h>
int n,op[4],num[10],_max=-100000000,_min=100000000;
void DFS(int remain,int res){
	if(remain==0){ //�����ڸ� ��� ��������� �ִ�, �ּڰ� �˻� 
		if(res>_max)
			_max=res;
		if(res<_min)
			_min=res;
		return;
	}
	//�� �����ں� �ӽð�� ��� �� DFS ȣ��
	if(op[0]>0){
		op[0]--;
		DFS(remain-1,res+num[n-remain]);
		op[0]++;
	}
	if(op[1]>0){
		op[1]--;
		DFS(remain-1,res-num[n-remain]);
		op[1]++;
	}
	if(op[2]>0){
		op[2]--;
		DFS(remain-1,res*num[n-remain]);
		op[2]++;
	}
	if(op[3]>0){
		op[3]--;
		DFS(remain-1,res/num[n-remain]);
		op[3]++;
	}
}
int main(void){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	for(i=0;i<4;i++)
		scanf("%d",&op[i]);
	DFS(n-1,num[0]); //DFS ȣ��
	printf("%d\n%d\n",_max,_min); //��� ���
	return 0;
}

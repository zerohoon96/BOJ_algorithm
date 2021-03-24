#include <stdio.h>
#include <string.h>
int n,op[4],num[10],_max=-100000000,_min=100000000;
void DFS(int remain,int res){
	int i,idx=0,tmp_res,tmp_op[4];
	if(remain==0){ //�����ڸ� ��� ��������� �ִ�, �ּڰ� �˻� 
		if(res>_max)
			_max=res;
		if(res<_min)
			_min=res;
		return;
	}
	memcpy(tmp_op,op,sizeof(int)*4);
	for(i=0;i<remain;i++){ //���� ������ �� ��ŭ DFS �Լ� ȣ�� 
		if(tmp_op[idx]==0){
			idx++;
			i--;
			continue;
		}
		tmp_res=res;
		tmp_op[idx]--;
		op[idx]--; //������ �迭 �ӽ� ����

		//�� �����ں� �ӽð�� ��� �� DFS ȣ��
		if(idx==0)
			tmp_res+=num[n-remain];
		else if(idx==1)
			tmp_res-=num[n-remain];
		else if(idx==2)
			tmp_res*=num[n-remain];
		else
			tmp_res/=num[n-remain];
		DFS(remain-1,tmp_res);

		op[idx]++; //������ �迭 ����
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

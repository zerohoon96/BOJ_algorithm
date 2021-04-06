#include <stdio.h>
int n,info[500][501],dp[500];
int craft(int num){
	int i,tmp,res=0;
	if(dp[num]!=-1) //�̹� dp���� �ִ� ��� �� ���� 
		return dp[num];
	i=1;
	while(1){ //�̸� ����� �ϴ� �ǹ� �߿� ���� ���� �ɸ��� �ð� ���� 
		if(info[num][i]==-1) //���̻� ����� �ϴ� �ǹ��� ������ break
			break;
		tmp=craft(info[num][i]-1);
		if(tmp>res) //����� ������Ʈ 
			res=tmp;
		i++;
	}
	return dp[num]=info[num][0]+res;
}
int main(void){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		j=0;
		while(1){ //�� �ǹ��� ���� �ð��� ���� ����� �ϴ� �ǹ� ��� ���� 
			scanf("%d",&info[i][j]);
			if(info[i][j]==-1)
				break;
			j++;
		}
		dp[i]=-1; //dp�迭 �ʱ�ȭ 
	}
	for(i=0;i<n;i++) //�ǹ��� �� ���� 
		craft(i);
	for(i=0;i<n;i++) //�� ��� 
		printf("%d\n",dp[i]);
	return 0;
}

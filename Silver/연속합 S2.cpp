#include <stdio.h>
int main(void){
	int n,i,dp,tmp,res;
	scanf("%d%d",&n,&dp);
	res=dp; //�ʱ� �ִ��� ���� 
	for(i=1;i<n;i++){
		scanf("%d",&tmp);
		if(tmp>dp+tmp) //dp���� �Էµ� ������ ��ü (��ü�ϴ� ���� ���� ���忡�� �ִ�) 
			dp=tmp;
		else //dp���� �Էµ� ���� ���� (���� ���� ���ϴ� ���� ���� ���忡�� �ִ�) 
			dp+=tmp;
		if(dp>res) //�ִ��� �˻� 
			res=dp;
	}
	printf("%d\n",res); //��� ��� 
	return 0;
}

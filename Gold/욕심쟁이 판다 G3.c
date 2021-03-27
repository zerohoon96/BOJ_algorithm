#include <stdio.h>
#include <stdlib.h>
int n,**wood,**dp;
int panda(int i,int j){
	int res=0;
	if(dp[i][j]>-1) //�̹� dp���� ����� ��� dp�� ���� 
		return dp[i][j];
	if(i>0){ //����� �˻� 
		if(wood[i-1][j]>wood[i][j]) //���纸�� ū ��츸 �˻�
			dp[i-1][j]=res=panda(i-1,j);
	}
	if(i<n-1){ //����� �˻� 
		if(wood[i+1][j]>wood[i][j]){ //���纸�� ū ��츸 �˻�
			dp[i+1][j]=panda(i+1,j);
			if(dp[i+1][j]>res) //4������ �ִ� �˻� 
				res=dp[i+1][j];
		}
	}
	if(j>0){ //����� �˻� 
		if(wood[i][j-1]>wood[i][j]){ //���纸�� ū ��츸 �˻�
			if(dp[i][j-1]==-1) //dp���� ���� ä������ ������ �� ����
				dp[i][j-1]=panda(i,j-1);
			if(dp[i][j-1]>res) //4������ �ִ� �˻� 
				res=dp[i][j-1];
		}
	}
	if(j<n-1){ //����� �˻� 
		if(wood[i][j+1]>wood[i][j]){ //���纸�� ū ��츸 �˻�
			dp[i][j+1]=panda(i,j+1);
			if(dp[i][j+1]>res) //4������ �ִ� �˻�
				res=dp[i][j+1];
		}
	}
	return dp[i][j]=res+1; //4������ �ִ�+1 ����. 4���� ��� �����ص� 1 ����(�Ϸ�� �� �� �����Ƿ�) 
}
int main(void){
	int i,j,tmp,res=0;
	scanf("%d",&n);
	//�޸� �����Ҵ� 
	wood=(int**)malloc(sizeof(int*)*n);	
	dp=(int**)malloc(sizeof(int*)*n);	
	for(i=0;i<n;i++){
		wood[i]=(int*)malloc(sizeof(int)*n);
		dp[i]=(int*)malloc(sizeof(int)*n);
		for(j=0;j<n;j++){
			scanf("%d",&wood[i][j]);
			dp[i][j]=-1;
		}
	}
	//����Լ��� ȣ���ϸ� �� ã�� dp[i][j] : ���� ��ġ���� �ִ��� �� �� �ִ� �ϼ� 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if((tmp=panda(i,j))>res)
				res=tmp;
		}
	}
	printf("%d\n",res); //�� ���
	//�޸� ���� ���� 
	for(i=0;i<n;i++){
		free(wood[i]);
		free(dp[i]);
	}
	free(wood);
	free(dp);
	return 0;
}

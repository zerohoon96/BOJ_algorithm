//1�������� 
#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j,tmp,left,right,num;
	scanf("%d",&n);
	vector<int> curr(n);
	scanf("%d",&curr[0]);
	for(i=2;i<=n;i++){ //2��° ���κ��� �� ������Ʈ 
		for(j=0;j<i;j++){
			left=right=0;
			scanf("%d",&num);
			if(j>0) //���� ��� (�̸� ����� ���� ���� ������ ���)
				left=num+tmp; 
			if(j<i-1){ //������ ��� (�Ŀ� curr[j] ���� ������ ������ �̸� ����) 
				right=num+curr[j];
				tmp=curr[j]; 
			}
			left>right?curr[j]=left:curr[j]=right; //����, ������ ���� ���ؼ� �� ���� 
		}
	}
	tmp=curr[0]; //�ִ밪�� ã�� ��� 
	for(i=1;i<n;i++){
		if(curr[i]>tmp)
			tmp=curr[i];
	}
	printf("%d\n",tmp);
	return 0;
}
/* 2�������� 
#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j,mini,left,right,num;
	scanf("%d",&n);
	vector<vector<int> > curr(n,vector<int>(n)); //n*n ũ�� ���� ���� 
	scanf("%d",&curr[0][0]);
	for(i=1;i<n;i++){ //2��° ���κ��� �� ������Ʈ 
		for(j=0;j<=i;j++){
			left=right=0;
			scanf("%d",&num);
			if(j>0) //���� ���
				left=num+curr[i-1][j-1]; 
			if(j<i) //������ ��� 
				right=num+curr[i-1][j];
			left>right?curr[i][j]=left:curr[i][j]=right; //����, ������ ���� ���ؼ� �� ���� 
		}
	}
	mini=curr[n-1][0]; //�ִ밪�� ã�� ��� 
	for(i=1;i<n;i++){
		if(curr[n-1][i]>mini)
			mini=curr[n-1][i];
	}
	printf("%d\n",mini);
	return 0;
}
*/

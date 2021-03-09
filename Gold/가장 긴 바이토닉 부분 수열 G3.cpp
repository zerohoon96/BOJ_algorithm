#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j,tmp,res=0;
	scanf("%d",&n);
	vector<int> arr(n),inc(n),dec(n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	for(i=0;i<n;i++){ //LIS(Longest Increasing Subsequence) �迭 ���ϱ� 
		tmp=0;
		for(j=0;j<i;j++){
			if(arr[j]<arr[i]&&inc[j]>tmp)
				tmp=inc[j];
		}
		inc[i]=tmp+1;
	}
	
	for(i=n-1;i>=0;i--){ //LDS(Longest Decreasing Subsequence) �迭 ���ϱ� 
		tmp=0;
		for(j=n-1;j>i;j--){
			if(arr[j]<arr[i]&&dec[j]>tmp)
				tmp=dec[j];
		}
		dec[i]=tmp+1;
	}

	for(i=0;i<n;i++){ //���� �� ������� ���� ���ϱ� ( ������� ���� �� ����+������� ���� �� ����-1(������� �ߺ�) ) 
		tmp=inc[i]+dec[i]-1;
		if(tmp>res)
			res=tmp;
	}
	printf("%d\n",res);
	return 0;
}

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int n,n1,n2,i,j,data,res=0;
	scanf("%d",&n);
	vector<pair<int,int> >arr(n);
	vector<int> dp(n);
	for(i=0;i<n;i++){ //������ ������ pair�� ���Ϳ� ���� 
		scanf("%d%d",&n1,&n2);
		arr[i]=make_pair(n1,n2);
	}
	sort(arr.begin(),arr.end()); //b�� �˻��ϵ��� ���� 
	for(i=0;i<n;i++){
		n1=arr[i].second;
		data=0;
		for(j=0;j<i;j++){ //��ġ�� �ʴ� ���� dp�� �ִ� ���� 
			n2=arr[j].second;
			if(n1>n2&&dp[j]>data)
				data=dp[j];
		}
		dp[i]=data+1; //���ο� dp�� ���� 
		if(dp[i]>res) //�ִ� �˻� 
			res=dp[i];
	}
	printf("%d\n",n-res); //�ִ� ��ġ ���� - 1 
	return 0;
}

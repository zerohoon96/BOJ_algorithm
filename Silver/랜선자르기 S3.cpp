#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int i,n,k,res=0;
	long long start,end,cur;
	scanf("%d%d",&k,&n);
	vector<int> arr(k);
	
	for(i=0;i<k;i++) //�� �Է� 
		scanf("%d",&arr[i]);
	
	sort(arr.begin(),arr.end()); //�ּڰ� ���� 
	cur=arr[0];
	for(i=0;i<k;i++){ //���� �ּڰ����� �������� ������ ���� ���� ���� 
		res+=arr[i]/cur;
	}
	if(res<n){ //�ּڰ����� ���� ����� ���� Ž�� start���� ���� 
		while(1){
			res=0; 
			cur/=2;
			if(cur==0){ //0���� ���� �� �����Ƿ� 1�� start�� 1�� ���� 
				start=1;
				break;
			}
			for(i=0;i<k;i++)
				res+=arr[i]/cur;
			if(res>n){
				start=cur;
				break;
			}
		}
	}
	else{
		start=cur;
	}
	end=arr[k-1]; //end�� �ִ����� ���� 
	cur=(start+end)/2;
	while(cur!=start){ //����Ž������ ���� ã�������� ����
		res=0;
		for(i=0;i<k;i++)
			res+=arr[i]/cur;
		if(res<n){
			end=cur;
		}
		else{
			start=cur;
		}
		cur=(start+end)/2;
	}
	printf("%lld\n",cur); //�������� ��� 
	return 0;
}

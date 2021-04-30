#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int i,n,m,tmp,left,right,mid;
	bool flag;
	scanf("%d",&n);
	vector<int> arr(n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr.begin(),arr.end()); //�̺�Ž���� �迭 ���� 
	
	scanf("%d",&m); //���� Ƚ�� 
	for(i=0;i<m;i++){ 
		scanf("%d",&tmp);
		left=0;
		right=n-1;
		flag=false;
		while(left<=right){ //�̺�Ž�� ���� 
			mid=(left+right)/2;
			if(arr[mid]==tmp){
				flag=true;
				break;
			}
			else if(arr[mid]>tmp)
				right=mid-1;
			else
				left=mid+1;
		}
		if(flag)
			puts("1");
		else
			puts("0");
	}
	return 0;
}

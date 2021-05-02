#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int target;
int my_lower_bound(int left,int right){ //target보다 같거나 작은 수 중에서 가장 큰 수 
	int mid;
	if(left>=right)
		return right;
	mid=(left+right)/2;
	if(arr[mid]<target)
		return my_lower_bound(mid+1,right);
	else
		return my_lower_bound(left,mid);
}
int my_upper_bound(int left,int right){ //target보다 큰 수 중에서 가장 작은 수 
	int mid;
	if(left>=right)
		return right;
	mid=(left+right)/2;
	if(arr[mid]<=target)
		return my_upper_bound(mid+1,right);
	else
		return my_upper_bound(left,mid);
}

int main(void){
	int n,m,i,left,right;
	scanf("%d",&n);
	arr.resize(n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr.begin(),arr.end());
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&target);
		left=my_lower_bound(0,n);
		if(arr[left]!=target){
			printf("0 ");
			continue;
		}		
		right=my_upper_bound(left,n);
		printf("%d ",right-left);
	}
	return 0;
}

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int n,m,i,tmp,res,left,right,mid;
	scanf("%d",&n);
	vector<int> arr(n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr.begin(),arr.end());
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&tmp);
		left=0;
		right=n-1;
		res=0;
		while(left<=right){
			mid=(left+right)/2;
			if(arr[mid]==tmp){
				res=1;
				break;
			}
			else if(arr[mid]>tmp)
				right=mid-1;
			else
				left=mid+1;
		}
		printf("%d ",res);
	}
	return 0;
}

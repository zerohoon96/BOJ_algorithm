#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int n,i,sum=0;
	scanf("%d",&n);
	vector<int> arr(n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr.begin(),arr.end());
	sum=arr[0];
	for(i=1;i<n;i++){
		arr[i]+=arr[i-1];
		sum+=arr[i];
	}
	printf("%d\n",sum);
	return 0;
} 

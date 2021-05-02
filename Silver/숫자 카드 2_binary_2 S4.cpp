#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[500001];
int main(void){
	int i,n,m,tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&tmp);
		printf("%ld ",upper_bound(arr,arr+n,tmp)-lower_bound(arr,arr+n,tmp));
	}
	return 0;
}

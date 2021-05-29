#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[1000000];
int* merge(int left,int mid,int right){
	int i,j,idx_1=left,idx_2=mid+1,idx_3=0;
	int *res=(int*)malloc(sizeof(int)*(right-left+1));

	while(idx_1<=mid&&idx_2<=right){
		if(arr[idx_1]<arr[idx_2])
			res[idx_3++]=arr[idx_1++];
		if(arr[idx_2]<arr[idx_1])
			res[idx_3++]=arr[idx_2++];
	}
	while(idx_1<=mid)
		res[idx_3++]=arr[idx_1++];
	while(idx_2<=right)
		res[idx_3++]=arr[idx_2++];
	return res;
}
void sort_arr(int left,int right){
	int *merge_res,mid;
	if(left>=right)
		return;
	mid=(left+right)/2;
	sort_arr(left,mid);
	sort_arr(mid+1,right);
	merge_res=merge(left,mid,right);
	memcpy(arr+left,merge_res,sizeof(int)*(right-left+1));
}
int main(void){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort_arr(0,n-1);
	for(i=0;i<n;i++)
		printf("%d\n",arr[i]);
	return 0;
}

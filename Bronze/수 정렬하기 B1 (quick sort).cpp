#include <stdio.h>
int arr[1000000];
void quick_sort(int left,int right){
	int low,high,pivot,tmp;
	if(left>=right)
		return;
	
	pivot=left;
	low=pivot+1;
	high=right;
	
	while(low<=high){
		while(arr[low]<arr[pivot])
			low++;
	
		while(arr[high]>arr[pivot])
			high--;
		
		if(low<high){
			tmp=arr[low];
			arr[low]=arr[high];
			arr[high]=tmp;
		}
	}
	
	tmp=arr[high];
	arr[high]=arr[pivot];
	arr[pivot]=tmp;
	pivot=high;
	
	quick_sort(left,pivot-1);
	quick_sort(pivot+1,right);
}
int main(void){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quick_sort(0,n-1);
	for(i=0;i<n;i++)
		printf("%d\n",arr[i]);
	return 0;
}

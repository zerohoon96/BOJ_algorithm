#include <stdio.h>
int main(void){
	int i,j,n,tmp,arr[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++){
		for(j=1;j<n-i;j++){
			if(arr[j-1]>arr[j]){
				tmp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=tmp;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\n",arr[i]);
	return 0;
}

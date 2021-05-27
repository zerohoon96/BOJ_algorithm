#include <stdio.h>
int main(void){
	int n,i,j,tmp,arr[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		for(j=i-1;j>=0;j--){
			if(arr[j]>tmp)
				arr[j+1]=arr[j];
			else
				break;
		}
		arr[j+1]=tmp;
	}
	for(i=0;i<n;i++)
		printf("%d\n",arr[i]);
	return 0;
}

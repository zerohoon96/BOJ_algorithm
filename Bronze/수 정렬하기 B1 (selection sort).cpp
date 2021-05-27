#include <stdio.h>
int main(void){
	int i,j,n,idx,tmp,arr[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++){
		idx=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[idx])
				idx=j;
		}
		if(idx==i)
			continue;
		else{
			tmp=arr[i];
			arr[i]=arr[idx];
			arr[idx]=tmp;
		}
	}
	for(i=0;i<n;i++)
		printf("%d\n",arr[i]);
	return 0;
}

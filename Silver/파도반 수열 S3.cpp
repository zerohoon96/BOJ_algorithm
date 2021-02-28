#include <stdio.h>
int main(void){
	int n,i,tmp;
	long long res[100]={1,1,1,2,2};
	for(i=5;i<100;i++)
		res[i]=res[i-1]+res[i-5];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		printf("%lld\n",res[tmp-1]);
	}
	return 0;
}

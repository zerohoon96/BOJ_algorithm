#include <stdio.h>
int a,b,c;
long long multiple(int n){
	long long res;
	if(n==1)
		return a%c;
	res=multiple(n/2);
	res=res*res%c;
	if(n%2==1)
		res=res*a%c;
	return res;
}
int main(void){
	scanf("%d%d%d",&a,&b,&c);
	printf("%lld\n",multiple(b));
	return 0;
}

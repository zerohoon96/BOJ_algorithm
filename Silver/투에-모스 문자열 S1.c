#include <stdio.h>
long long my_pow(int n1,int n2){
	long long res=1;
	for(int i=0;i<n2;i++)
		res*=n1;
	return res;
}
int get_k(long long n){ //구간 탐색
	long long cur;
	int res;
	res=-1;
	cur=1;
	while(cur<n){
		cur*=2;
		res++;
	}
	return res;
}
int get_res(long long n,long long cur){ //정답을 얻는 함수
	int res,k;
	if(n-cur==1||(k=get_k(n-cur))<0)
		return 1;
	res=get_res(n-cur,my_pow(2,k));
	return res==1?0:1;
}
int main(void){
	long long n;
	int k;
	scanf("%lld",&n);
	if((k=get_k(n))<0)
		printf("0\n");
	else
		printf("%d\n",get_res(n,my_pow(2,k)));
	return 0;
}

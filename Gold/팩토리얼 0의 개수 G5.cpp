#include <stdio.h>
using namespace std;
int main(void){
	int m,num=0,tmp,ct=0;
	scanf("%d",&m);
	while(1){
		num+=5;
		tmp=num;
		while(tmp%5==0){
			tmp/=5;
			ct++;
		}
		if(ct==m){
			printf("%d\n",num);
			break;
		}
		if(ct>m){
			printf("-1\n");
			break;
		}
	}
	return 0;
}
#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i;
	long long price,sum=0;
	scanf("%d",&n);
	vector<long long> length(n-1); 
	vector<long long> cost(n);
	
	for(i=0;i<n-1;i++)
		scanf("%lld",&length[i]);
	for(i=0;i<n;i++)
		scanf("%lld",&cost[i]);
	
	for(i=0;i<n-1;i++){
		if(i==0||cost[i]<price)
			price=cost[i];
		sum+=price*length[i];
	}
	printf("%lld\n",sum);
	return 0;
}

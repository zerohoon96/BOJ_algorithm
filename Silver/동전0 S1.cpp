#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,cost,i,tmp,index=0,ct=0;
	scanf("%d%d",&n,&cost);
	vector<int> curr(n);
	for(i=0;i<n;i++){
		scanf("%d",&curr[i]);
		if(curr[i]<cost)
			index=i;
	}
	
	for(i=index;i>=0;i--){
		tmp=cost/curr[i];
		cost-=curr[i]*tmp;
		ct+=tmp;
	}
	printf("%d\n",ct);
	return 0;
}

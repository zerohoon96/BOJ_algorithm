#include <stdio.h>
#include <tr1/unordered_map>
using namespace std::tr1;
int main(void){
	int n,i,tmp;
	unordered_map<int,int> umap;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		umap[tmp]++;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		printf("%d ",umap[tmp]);
	}
	return 0;
}

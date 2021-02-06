#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int arr[10001];
struct edge{
	int n1,n2,weigh;
	edge(int a,int b,int c){
		n1=a;
		n2=b;
		weigh=c;
	}
	bool operator<(edge &b){
		return weigh<b.weigh;
	}
};

int Find(int num){
	if(num==arr[num])
		return num;
	else
		return arr[num]=Find(arr[num]);
}

void Union(int n1,int n2){
	int set1,set2;
	set1=Find(n1);
	set2=Find(n2);
	
	arr[set1]=set2;
}
int main(void){
	int i,n1,n2,weigh,sum=0;
	vector<edge> info;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&n1,&n2,&weigh);
		info.push_back(edge(n1,n2,weigh));
	}
	
	for(i=1;i<=10000;i++)
		arr[i]=i;
	sort(info.begin(),info.end());
	for(i=0;i<m;i++){
		n1=info[i].n1;
		n2=info[i].n2;
		weigh=info[i].weigh;
		if(Find(n1)==Find(n2))
			continue;
		Union(n1,n2);
		sum+=weigh;
	}
	printf("%d\n",sum);
	return 0;
}

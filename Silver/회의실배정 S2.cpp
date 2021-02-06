#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting{
	int start,end;
	meeting(int a,int b){
		start=a;
		end=b;
	}
	bool operator<(meeting &b){
		if(end==b.end) //종료시간이 같은 경우 시작시간으로 정렬 
			return start<b.start;
		else 
			return end<b.end;
	}
};
int main(void){
	int n,i,start,end,ct=1;
	vector<meeting> info;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&start,&end);
		info.push_back(meeting(start,end));
	}
	sort(info.begin(),info.end()); //종료시간 기준으로 오름차순 정렬
	
	end=info[0].end; 
	for(i=1;i<n;i++){ //탐색 
		if(info[i].start>=end){
			end=info[i].end;
			ct++;
		}
	}
	printf("%d\n",ct);
	return 0;
}

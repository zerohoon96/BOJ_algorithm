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
		if(end==b.end) //����ð��� ���� ��� ���۽ð����� ���� 
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
	sort(info.begin(),info.end()); //����ð� �������� �������� ����
	
	end=info[0].end; 
	for(i=1;i<n;i++){ //Ž�� 
		if(info[i].start>=end){
			end=info[i].end;
			ct++;
		}
	}
	printf("%d\n",ct);
	return 0;
}

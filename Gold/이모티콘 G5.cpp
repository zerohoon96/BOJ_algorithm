#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct info{
	int total;
	int clip;
	int sec;
	info(int a,int b,int c){
		total=a;
		clip=b;
		sec=c;
	}
}; 
int main(void){
	int s,sec=0,total,clip;
	queue<info> que;
	scanf("%d",&s);
	vector<vector<bool> > check(2*s,vector<bool>(2*s));	
	que.push(info(1,0,0));
	check[1][0]=true;
	while(!que.empty()){
		total=que.front().total;
		clip=que.front().clip;
		sec=que.front().sec;
		que.pop();
		if(total==s){
			printf("%d\n",sec);
			break;
		}
		
		if(total<s){
			if(total>0){ //클립보드에 복사 
				if(check[total][total]==false){
					check[total][total]=true;
					que.push(info(total,total,sec+1));
				}
			}
			if(clip>0){ //클립보드에서 붙여넣기 
				if(check[total+clip][clip]==false){
					check[total+clip][clip]=true;
					que.push(info(total+clip,clip,sec+1));
				}
			}
		}
		
		if(total>0){ //하나 지우기 
			if(check[total-1][clip]==false){
				check[total-1][clip]=true;
				que.push(info(total-1,clip,sec+1));
			}
		}
	}
	return 0;
}

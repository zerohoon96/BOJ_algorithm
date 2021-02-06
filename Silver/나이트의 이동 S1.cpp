#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct info{
	int x,y,count;
	info(int a,int b,int c){
		x=a;
		y=b;
		count=c;
	}
}; 
int main(void){
	int n,i,j,ct,size,x1,x2,y1,y2,tmpx,tmpy;
	int arr1[8]={2,2,-2,-2,1,1,-1,-1},arr2[8]={1,-1,1,-1,2,-2,2,-2};
	bool flag;
	vector<int> res;
	scanf("%d",&n);
	for(i=0;i<n;i++){ //n번 반복 
		scanf("%d",&size);
		vector<vector<bool> > board(size,vector<bool>(size));
		queue<info> pos;
		scanf("%d%d",&x1,&y1);
		scanf("%d%d",&x2,&y2);
		board[x1][y1]=true;
		pos.push(info(x1,y1,0));
		flag=false;
		if(x1==x2&&y1==y2){ //찾으려는 위치가 현재위치면 답은 0 
			res.push_back(0);
			continue;
		}
		while(!pos.empty()){ //정답 찾기 
			x1=pos.front().x;
			y1=pos.front().y;
			ct=pos.front().count;
			pos.pop();
			for(j=0;j<8;j++){ //나이트 이동 
				tmpx=x1+arr1[j];
				tmpy=y1+arr2[j];
				if(tmpx>=size||tmpx<0)
					continue;
				if(tmpy>=size||tmpy<0)
					continue;
				if(board[tmpx][tmpy]==true) 
					continue;
				if(tmpx==x2&&tmpy==y2){ //정답 찾음 
					res.push_back(ct+1);
					flag=true;
					break;
				}
				board[tmpx][tmpy]=true;
				pos.push(info(tmpx,tmpy,ct+1));
			}
			if(flag)
				break; 
		}
	}
	for(i=0;i<n;i++)
		printf("%d\n",res[i]);
	return 0;
}

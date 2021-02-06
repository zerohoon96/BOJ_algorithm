#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int arr[9][9];
vector<pair<int,int> > blank;
void find(int n){
	int i,j,k,row,col,x,y;
	bool flag;
	if(n==blank.size()){ //빈칸을 모두 찾은 경우 종료 
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				printf("%d ",arr[i][j]);
			puts("");
		}
		exit(0);
	}
	row=blank[n].first; //row,column 저장 
	col=blank[n].second;
	
	for(i=1;i<=9;i++){ //빈칸에 1~9를 넣으면서 탐색 
		flag=true;
		arr[row][col]=i;
		for(j=0;j<9;j++){ //세로줄 비교 
			if(j==row)
				continue;
			if(arr[row][col]==arr[j][col]){
				flag=false;
				break;
			}
		}
		if(!flag)
			continue;
		for(j=0;j<9;j++){ //가로줄 비교 
			if(j==col)
				continue;
			if(arr[row][col]==arr[row][j]){
				flag=false;
				break;
			}	
		}
		if(!flag)
			continue;
		x=row/3*3;
		y=col/3*3;
		for(j=x;j<x+3;j++){ //3*3 비교 
			for(k=y;k<y+3;k++){
				if(j==row&&k==col)
					continue;
				if(arr[row][col]==arr[j][k]){
					flag=false;
					break;
				}
			}
			if(!flag)
				break;
		}
		if(!flag)
			continue;
		find(n+1); //숫자를 채울 수 있으면 다음 단계 진행 
	}
	arr[row][col]=0; //값 초기화 
}
int main(void){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==0) //채워야 하는 칸을 모음 
				blank.push_back(make_pair(i,j));
		}
	}
	find(0);
	return 0;
}

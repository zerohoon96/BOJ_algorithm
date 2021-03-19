#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,dp[1000][1000];
char arr[1000][1000];
int square(int i,int j){
	if(i>=n||j>=m) //범위를 벗어난 경우 0 리턴 
		return 0;
	if(arr[i][j]=='0') //해당 자리가 0인 경우 0 리턴 
		return 0;
	if(dp[i][j]>0) //이미 dp값이 존재하는 경우 해당값 리턴 
		return dp[i][j];
	return dp[i][j]=min(square(i+1,j),min(square(i+1,j+1),square(i,j+1)))+1; //dp에 새로운 값 저장 (그 과정에서 연결된 하위 dp값도 저장됨) 
}
int main(void){
	int i,j,tmp,res=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%s",arr[i]);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(arr[i][j]=='1'){ //1인 경우에만 함수 호출
				tmp=square(i,j);
				if(res<tmp) //최댓값 판별
					res=tmp;
			}
		}
	}
	printf("%d\n",res*res);
	return 0;
}

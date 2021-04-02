#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,s,m,i,j,flag;
	scanf("%d%d%d",&n,&s,&m);
	vector<int> v(n+1);
	vector<vector<int> > dp(n+1,vector<int>(m+1));
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	dp[0][s]=1;
	for(i=1;i<=n;i++){
		flag=0;
		for(j=0;j<=m;j++){
			if(j-v[i]>=0){
				if(dp[i-1][j-v[i]]==1){ //이전값+현재볼륨=현재값 
					dp[i][j]=1;
					flag=1;
					continue;
				}
			}
			if(j+v[i]<=m){
				if(dp[i-1][j+v[i]]==1){ //이전값-현재볼륨=현재값 
					dp[i][j]=1;
					flag=1;
				}
			}
		}
		if(flag==0) //현재 줄이 모두 실패한 경우 break 
			break;
	}
	//결과 출력 
	if(flag!=0){
		for(i=m;i>=0;i--){
			if(dp[n][i]==1)
				break;
		}
		printf("%d\n",i);
	}
	else
		printf("-1");
	return 0;
}

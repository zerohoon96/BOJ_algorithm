#include <stdio.h>
int n,info[500][501],dp[500];
int craft(int num){
	int i,tmp,res=0;
	if(dp[num]!=-1) //이미 dp값이 있는 경우 값 리턴 
		return dp[num];
	i=1;
	while(1){ //미리 지어야 하는 건물 중에 가장 오래 걸리는 시간 저장 
		if(info[num][i]==-1) //더이상 지어야 하는 건물이 없으면 break
			break;
		tmp=craft(info[num][i]-1);
		if(tmp>res) //결과값 업데이트 
			res=tmp;
		i++;
	}
	return dp[num]=info[num][0]+res;
}
int main(void){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		j=0;
		while(1){ //현 건물을 짓는 시간과 먼저 지어야 하는 건물 목록 저장 
			scanf("%d",&info[i][j]);
			if(info[i][j]==-1)
				break;
			j++;
		}
		dp[i]=-1; //dp배열 초기화 
	}
	for(i=0;i<n;i++) //건물별 값 저장 
		craft(i);
	for(i=0;i<n;i++) //답 출력 
		printf("%d\n",dp[i]);
	return 0;
}

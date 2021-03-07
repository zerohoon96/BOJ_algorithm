#include <stdio.h>
int main(void){
	int n,i,dp,tmp,res;
	scanf("%d%d",&n,&dp);
	res=dp; //초기 최대합 설정 
	for(i=1;i<n;i++){
		scanf("%d",&tmp);
		if(tmp>dp+tmp) //dp값을 입력된 값으로 교체 (교체하는 것이 현재 입장에서 최댓값) 
			dp=tmp;
		else //dp값에 입력된 값을 더함 (원래 값에 더하는 것이 현재 입장에서 최댓값) 
			dp+=tmp;
		if(dp>res) //최대합 검사 
			res=dp;
	}
	printf("%d\n",res); //결과 출력 
	return 0;
}

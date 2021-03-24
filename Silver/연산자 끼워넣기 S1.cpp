#include <stdio.h>
#include <string.h>
int n,op[4],num[10],_max=-100000000,_min=100000000;
void DFS(int remain,int res){
	if(remain==0){ //연산자를 모두 사용했을때 최댓값, 최솟값 검사 
		if(res>_max)
			_max=res;
		if(res<_min)
			_min=res;
		return;
	}
	//각 연산자별 임시결과 계산 후 DFS 호출
	if(op[0]>0){
		op[0]--;
		DFS(remain-1,res+num[n-remain]);
		op[0]++;
	}
	if(op[1]>0){
		op[1]--;
		DFS(remain-1,res-num[n-remain]);
		op[1]++;
	}
	if(op[2]>0){
		op[2]--;
		DFS(remain-1,res*num[n-remain]);
		op[2]++;
	}
	if(op[3]>0){
		op[3]--;
		DFS(remain-1,res/num[n-remain]);
		op[3]++;
	}
}
int main(void){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	for(i=0;i<4;i++)
		scanf("%d",&op[i]);
	DFS(n-1,num[0]); //DFS 호출
	printf("%d\n%d\n",_max,_min); //결과 출력
	return 0;
}

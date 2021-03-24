#include <stdio.h>
#include <string.h>
int n,op[4],num[10],_max=-100000000,_min=100000000;
void DFS(int remain,int res){
	int i,idx=0,tmp_res,tmp_op[4];
	if(remain==0){ //연산자를 모두 사용했을때 최댓값, 최솟값 검사 
		if(res>_max)
			_max=res;
		if(res<_min)
			_min=res;
		return;
	}
	memcpy(tmp_op,op,sizeof(int)*4);
	for(i=0;i<remain;i++){ //남은 연산자 수 만큼 DFS 함수 호출 
		if(tmp_op[idx]==0){
			idx++;
			i--;
			continue;
		}
		tmp_res=res;
		tmp_op[idx]--;
		op[idx]--; //연산자 배열 임시 변형

		//각 연산자별 임시결과 계산 후 DFS 호출
		if(idx==0)
			tmp_res+=num[n-remain];
		else if(idx==1)
			tmp_res-=num[n-remain];
		else if(idx==2)
			tmp_res*=num[n-remain];
		else
			tmp_res/=num[n-remain];
		DFS(remain-1,tmp_res);

		op[idx]++; //연산자 배열 복구
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

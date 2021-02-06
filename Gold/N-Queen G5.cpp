#include <stdio.h>
#include <math.h>
int n,res=0;
int arr[15];
void find(int cur){
	int i,j;
	if(cur==n){ //답을 발견한 경우 
		res++;
		return;
	}
	for(i=0;i<n;i++){ //열 번호를 대입하며 찾음 
		for(j=0;j<cur;j++){
			if(i==arr[j]) //같은 열 
				break;
			if(abs(i-arr[j])==cur-j) //대각선 겹침 
				break;
		}
		if(j<cur) //조건 만족 x 
			continue;
		arr[cur]=i;
		find(cur+1); 
		arr[cur]=0;
	}
}
int main(void){
	scanf("%d",&n);
	find(0);
	printf("%d\n",res);
	return 0;
}

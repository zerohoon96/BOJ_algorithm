#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(void){
	int i,n,data,arr[3],tmp[3];
	scanf("%d",&n);
	//1회 데이터 세팅 
	arr[0]=0;
	arr[2]=-1;
	scanf("%d",&arr[1]);
	
	for(i=1;i<n;i++){ //n-1번 반복. 연속으로 마신 횟수(0~2)에 따라서 최댓값을 갱신 
		scanf("%d",&data); 
		memcpy(tmp,arr,sizeof(int)*3);
		//0번 연속으로 마시고 온 경우 처리 
		arr[1]=tmp[0]+data;
		
		//1번 연속으로 마시고 온 경우 처리		
		arr[0]=max(arr[0],tmp[1]);
		arr[2]=tmp[1]+data;
		
		//2번 연속으로 마시고 온 경우 처리
		if(tmp[2]>0)
			arr[0]=max(arr[0],tmp[2]);
	}
	printf("%d\n",max(arr[0],max(arr[1],arr[2]))); //최댓값 출력 
	return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j,tmp,res=0;
	scanf("%d",&n);
	vector<int> arr(n),inc(n),dec(n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	for(i=0;i<n;i++){ //LIS(Longest Increasing Subsequence) 배열 구하기 
		tmp=0;
		for(j=0;j<i;j++){
			if(arr[j]<arr[i]&&inc[j]>tmp)
				tmp=inc[j];
		}
		inc[i]=tmp+1;
	}
	
	for(i=n-1;i>=0;i--){ //LDS(Longest Decreasing Subsequence) 배열 구하기 
		tmp=0;
		for(j=n-1;j>i;j--){
			if(arr[j]<arr[i]&&dec[j]>tmp)
				tmp=dec[j];
		}
		dec[i]=tmp+1;
	}

	for(i=0;i<n;i++){ //가장 긴 바이토닉 수열 구하기 ( 현재까지 가장 긴 증가+현재부터 가장 긴 감소-1(현재숫자 중복) ) 
		tmp=inc[i]+dec[i]-1;
		if(tmp>res)
			res=tmp;
	}
	printf("%d\n",res);
	return 0;
}

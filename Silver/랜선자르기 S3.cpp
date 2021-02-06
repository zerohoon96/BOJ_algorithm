#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int i,n,k,res=0;
	long long start,end,cur;
	scanf("%d%d",&k,&n);
	vector<int> arr(k);
	
	for(i=0;i<k;i++) //값 입력 
		scanf("%d",&arr[i]);
	
	sort(arr.begin(),arr.end()); //최솟값 저장 
	cur=arr[0];
	for(i=0;i<k;i++){ //현재 최솟값으로 나눴을때 나오는 랜선 개수 구함 
		res+=arr[i]/cur;
	}
	if(res<n){ //최솟값으로 나눈 결과에 따라서 탐색 start지점 설정 
		while(1){
			res=0; 
			cur/=2;
			if(cur==0){ //0으로 나눌 수 없으므로 1로 start를 1로 설정 
				start=1;
				break;
			}
			for(i=0;i<k;i++)
				res+=arr[i]/cur;
			if(res>n){
				start=cur;
				break;
			}
		}
	}
	else{
		start=cur;
	}
	end=arr[k-1]; //end는 최댓값으로 설정 
	cur=(start+end)/2;
	while(cur!=start){ //이진탐색으로 답을 찾을때까지 진행
		res=0;
		for(i=0;i<k;i++)
			res+=arr[i]/cur;
		if(res<n){
			end=cur;
		}
		else{
			start=cur;
		}
		cur=(start+end)/2;
	}
	printf("%lld\n",cur); //최종답을 출력 
	return 0;
}

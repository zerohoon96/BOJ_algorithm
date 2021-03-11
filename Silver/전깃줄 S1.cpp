#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int n,n1,n2,i,j,data,res=0;
	scanf("%d",&n);
	vector<pair<int,int> >arr(n);
	vector<int> dp(n);
	for(i=0;i<n;i++){ //전깃줄 정보를 pair로 백터에 저장 
		scanf("%d%d",&n1,&n2);
		arr[i]=make_pair(n1,n2);
	}
	sort(arr.begin(),arr.end()); //b만 검사하도록 정렬 
	for(i=0;i<n;i++){
		n1=arr[i].second;
		data=0;
		for(j=0;j<i;j++){ //겹치지 않는 이전 dp의 최댓값 추출 
			n2=arr[j].second;
			if(n1>n2&&dp[j]>data)
				data=dp[j];
		}
		dp[i]=data+1; //새로운 dp값 생성 
		if(dp[i]>res) //최댓값 검사 
			res=dp[i];
	}
	printf("%d\n",n-res); //최대 설치 개수 - 1 
	return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<int,int> >arr(41); //0~40 항을 저장할 백터 
pair<int,int> fibo(int n,int ct1,int ct2){
	if(n==0) //0이면 0 출력 횟수를 추가 
		return make_pair(ct1+1,ct2);
	else if(n==1) //1이면 1 출력 횟수를 추가 
		return make_pair(ct1,ct2+1);

	if(arr[n].first>0&&arr[n].second>0) //n번째항 계산 결과 이미 존재 
		return arr[n];
	if(arr[n-1].first==0&&arr[n-1].second==0) //n-1 번째항 계산 결과 없음 
		arr[n-1]=fibo(n-1,ct1,ct2);
	
	if(arr[n-2].first==0&&arr[n-2].second==0) //n-2 번째항 계산 결과 없음 
		arr[n-2]=fibo(n-2,ct2,ct2);
	return arr[n]=make_pair(arr[n-1].first+arr[n-2].first,arr[n-1].second+arr[n-2].second); //n번째항 계산 후 리턴 
}
int main(void){
	int n,i,tmp;
	scanf("%d",&n); //테스트케이스 수 입력 
	vector<pair<int,int> > res(n); //결과 저장할 백터 
	for(i=0;i<n;i++){ //결과 저장 
		scanf("%d",&tmp);
		res[i]=fibo(tmp,0,0);
	}
	for(i=0;i<n;i++) //결과 출력 
		printf("%d %d\n",res[i].first,res[i].second);
	return 0;
}

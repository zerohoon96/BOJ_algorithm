#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<int,int> >arr(41); //0~40 ���� ������ ���� 
pair<int,int> fibo(int n,int ct1,int ct2){
	if(n==0) //0�̸� 0 ��� Ƚ���� �߰� 
		return make_pair(ct1+1,ct2);
	else if(n==1) //1�̸� 1 ��� Ƚ���� �߰� 
		return make_pair(ct1,ct2+1);

	if(arr[n].first>0&&arr[n].second>0) //n��°�� ��� ��� �̹� ���� 
		return arr[n];
	if(arr[n-1].first==0&&arr[n-1].second==0) //n-1 ��°�� ��� ��� ���� 
		arr[n-1]=fibo(n-1,ct1,ct2);
	
	if(arr[n-2].first==0&&arr[n-2].second==0) //n-2 ��°�� ��� ��� ���� 
		arr[n-2]=fibo(n-2,ct2,ct2);
	return arr[n]=make_pair(arr[n-1].first+arr[n-2].first,arr[n-1].second+arr[n-2].second); //n��°�� ��� �� ���� 
}
int main(void){
	int n,i,tmp;
	scanf("%d",&n); //�׽�Ʈ���̽� �� �Է� 
	vector<pair<int,int> > res(n); //��� ������ ���� 
	for(i=0;i<n;i++){ //��� ���� 
		scanf("%d",&tmp);
		res[i]=fibo(tmp,0,0);
	}
	for(i=0;i<n;i++) //��� ��� 
		printf("%d %d\n",res[i].first,res[i].second);
	return 0;
}

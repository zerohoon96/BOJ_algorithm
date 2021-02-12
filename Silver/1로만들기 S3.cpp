#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int main(void){
	int n,ct=0;
	scanf("%d",&n);
	vector<bool> arr(n+1,false);
	queue<pair<int,int> > que;
	que.push(make_pair(n,0));
	while(!que.empty()){
		n=que.front().first;
		ct=que.front().second;
		que.pop();
		if(n==1){
			ct--;
			break;
		}
		if(n%3==0&&n/3>0){ //3���� ����������� 0�� �ƴ�
			if(n/3==1)
				break; 
			if(!arr[n/3]){ //������� ���� ���� ����  
				arr[n/3]=true;
				que.push(make_pair(n/3,ct+1));
			}	
		}
		
		if(n%2==0&&n/2>0){ //2�� ����������� 0�� �ƴ� 
			if(n/2==1)
				break;
			if(!arr[n/2]){ //������� ���� ���� ���� 
				arr[n/2]=true;
				que.push(make_pair(n/2,ct+1));
			}
		}
		
		if(n-1==1)
			break;
		if(!arr[n-1]){ //������� ���� ���� ���� 
			arr[n-1]=true;
			que.push(make_pair(n-1,ct+1));
		} 
	}
	printf("%d\n",ct+1);
	return 0;
}

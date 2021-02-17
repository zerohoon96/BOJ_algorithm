#include <stdio.h>
#include <queue>
#include <vector> 
using namespace std;
int main(void){
	int n,i,tmp,val;
	priority_queue<int> max_heap,min_heap;
	scanf("%d",&n);
	vector<int> res(n); //중간값 저장할 백터 
	scanf("%d",&tmp);
	max_heap.push(tmp); //첫값을 max heap, 결과 백터에 저장 
	res[0]=tmp; 
	for(i=1;i<n;i++){
		scanf("%d",&tmp);
		if(i%2==1){ //지금까지 입력된 개수가 홀수-> min heap에 저장될 차례 
			val=max_heap.top();
			if(tmp>val) //min heap에 저장 
				min_heap.push(tmp*-1);
			else{ //값을 이동하고 max heap에 저장 
				min_heap.push(val*-1);
				max_heap.pop();
				max_heap.push(tmp);
			}
		}
		else{ //지금까지 입력된 개수가 짝수-> max heap에 저장될 차례 
			val=min_heap.top()*-1;
			if(tmp<val) //max heap에 저장 
				max_heap.push(tmp);
			else{ //값을 이동하고 min heap에 저장 
				max_heap.push(val);
				min_heap.pop();
				min_heap.push(tmp*-1); 
			} 	
		}
		res[i]=max_heap.top(); //중간값 저장 (무조건 max heap의 최대값) 
	}
	for(i=0;i<n;i++) //결과 출력 
		printf("%d\n",res[i]);
	return 0;
}

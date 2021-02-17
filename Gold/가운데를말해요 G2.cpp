#include <stdio.h>
#include <queue>
#include <vector> 
using namespace std;
int main(void){
	int n,i,tmp,val;
	priority_queue<int> max_heap,min_heap;
	scanf("%d",&n);
	vector<int> res(n); //�߰��� ������ ���� 
	scanf("%d",&tmp);
	max_heap.push(tmp); //ù���� max heap, ��� ���Ϳ� ���� 
	res[0]=tmp; 
	for(i=1;i<n;i++){
		scanf("%d",&tmp);
		if(i%2==1){ //���ݱ��� �Էµ� ������ Ȧ��-> min heap�� ����� ���� 
			val=max_heap.top();
			if(tmp>val) //min heap�� ���� 
				min_heap.push(tmp*-1);
			else{ //���� �̵��ϰ� max heap�� ���� 
				min_heap.push(val*-1);
				max_heap.pop();
				max_heap.push(tmp);
			}
		}
		else{ //���ݱ��� �Էµ� ������ ¦��-> max heap�� ����� ���� 
			val=min_heap.top()*-1;
			if(tmp<val) //max heap�� ���� 
				max_heap.push(tmp);
			else{ //���� �̵��ϰ� min heap�� ���� 
				max_heap.push(val);
				min_heap.pop();
				min_heap.push(tmp*-1); 
			} 	
		}
		res[i]=max_heap.top(); //�߰��� ���� (������ max heap�� �ִ밪) 
	}
	for(i=0;i<n;i++) //��� ��� 
		printf("%d\n",res[i]);
	return 0;
}

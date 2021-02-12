#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int m,n,i,j,n1,n2,n3,val=1;
	//freopen("input.txt","r",stdin); 
	scanf("%d%d",&m,&n);
	vector<int> arr(2*m-1); //데이터 저장 
	for(i=0;i<n;i++){ //n번의 날 처리. 오름차순 저장이므로 더해지는 지점 찾아서 성장값 누적 
		scanf("%d%d%d",&n1,&n2,&n3);
		if(n1<2*m-1&&n2>0) //범위 벗어나지 않고 1 성장이 0 아니면 성장값 1 누적 
			arr[n1]++;
		if(n1+n2<2*m-1){ //범위 벗어나지 않으면 2 성장 누적 
			if(n2>0)
				arr[n1+n2]++; //1 성장이 0 아니면 1 누적 (이미 1 성장에서 1 누적했으므로) 
			else
				arr[n1+n2]+=2; //1 성장이 0이면 2 누적 (1 성장에서 누적하지 않았으므로) 
		}
	}
	for(i=0;i<2*m-1;i++){ //누적한 값을 계산해서 배열 완성 
		if(arr[i]==0) //누적값 없으면 원래값 삽입 
			arr[i]=val;
		else{ //누적값 업데이트 
			val+=arr[i];
			arr[i]=val;
		}
	} 
	for(i=m-1;i>=0;i--){ //결과 출력. 거꾸로 저장돼있으므로 m-1부터 0까지 반복 
		printf("%d ",arr[i]);
		for(j=m;j<2*m-1;j++)
			printf("%d ",arr[j]);
		puts("");
	}
	return 0;
}

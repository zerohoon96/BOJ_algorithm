#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,R,G,B,tmp;
	scanf("%d",&n);
	vector<vector<int> > arr(n,vector<int>(3));
	scanf("%d%d%d",&arr[0][0],&arr[0][1],&arr[0][2]); //첫 R,G,B값 저장 
	for(i=1;i<n;i++){ //칠하려는 색과 겹치지 않는 색 중에 최솟값을 선택해서 색을 칠함(누적)  
		scanf("%d%d%d",&R,&G,&B);
		arr[i][0]=R+min(arr[i-1][1],arr[i-1][2]); //R을 더할 값 선택 
		arr[i][1]=G+min(arr[i-1][0],arr[i-1][2]); //G를 더할 값 선택 
		arr[i][2]=B+min(arr[i-1][0],arr[i-1][1]); //B를 더할 값 선택
	}
	printf("%d\n",min(min(arr[n-1][0],arr[n-1][1]),arr[n-1][2])); //최종값중 최소값 출력 
	return 0;
}

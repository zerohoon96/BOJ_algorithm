//1차원버전 
#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j,tmp,left,right,num;
	scanf("%d",&n);
	vector<int> curr(n);
	scanf("%d",&curr[0]);
	for(i=2;i<=n;i++){ //2번째 라인부터 값 업데이트 
		for(j=0;j<i;j++){
			left=right=0;
			scanf("%d",&num);
			if(j>0) //왼쪽 계산 (미리 저장된 원래 왼쪽 값으로 계산)
				left=num+tmp; 
			if(j<i-1){ //오른쪽 계산 (후에 curr[j] 값을 덮어씌우기 때문에 미리 저장) 
				right=num+curr[j];
				tmp=curr[j]; 
			}
			left>right?curr[j]=left:curr[j]=right; //왼쪽, 오른쪽 값을 비교해서 값 저장 
		}
	}
	tmp=curr[0]; //최대값을 찾고 출력 
	for(i=1;i<n;i++){
		if(curr[i]>tmp)
			tmp=curr[i];
	}
	printf("%d\n",tmp);
	return 0;
}
/* 2차원버전 
#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int n,i,j,mini,left,right,num;
	scanf("%d",&n);
	vector<vector<int> > curr(n,vector<int>(n)); //n*n 크기 백터 생성 
	scanf("%d",&curr[0][0]);
	for(i=1;i<n;i++){ //2번째 라인부터 값 업데이트 
		for(j=0;j<=i;j++){
			left=right=0;
			scanf("%d",&num);
			if(j>0) //왼쪽 계산
				left=num+curr[i-1][j-1]; 
			if(j<i) //오른쪽 계산 
				right=num+curr[i-1][j];
			left>right?curr[i][j]=left:curr[i][j]=right; //왼쪽, 오른쪽 값을 비교해서 값 저장 
		}
	}
	mini=curr[n-1][0]; //최대값을 찾고 출력 
	for(i=1;i<n;i++){
		if(curr[n-1][i]>mini)
			mini=curr[n-1][i];
	}
	printf("%d\n",mini);
	return 0;
}
*/

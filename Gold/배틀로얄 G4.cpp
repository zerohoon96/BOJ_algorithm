#include <stdio.h>
#include <vector>
using namespace std;
int main(void){
	int x,y,m,i,j,val,idx1=0,idx2=0;
	long long tmp;
	scanf("%d%d%d",&x,&y,&m);
	tmp=m;
	val=m;
	vector<int> enemy(x);
	vector<int> medi(y);
	for(i=0;i<x;i++){ //적들의 체력 입력 
		scanf("%d",&enemy[i]);
		tmp-=enemy[i];
	}
	for(i=0;i<y;i++){ //회복 체력 입력 
		scanf("%d",&medi[i]);
		tmp+=medi[i];
	}
	if(tmp<=0){ //회복 체력+현재 체력이 적들의 체력 합보다 같거나 작으면 못이김 
		puts("0");
		return 0;
	}
	for(i=0;i<x+y;i++){
		if(idx1==x){ //적을 모두 죽임 
			for(j=idx2;j<y;j++)
				printf("%d\n",j+1);
			break;
		}
		else if(idx2==y){ //약을 모두 먹음 
			for(j=idx1;j<x;j++)
				printf("%d\n",(j+1)*-1);
			break;
		}
		if(val>m/2){ //적을 죽일 수 있는 경우 
			val-=enemy[idx1++];
			printf("%d\n",idx1*-1);
		}
		else{ //회복약을 먹어야 하는 경우 
			val+=medi[idx2++];
			printf("%d\n",idx2);
		}
	}
	return 0;
}

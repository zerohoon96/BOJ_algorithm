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
	for(i=0;i<x;i++){ //������ ü�� �Է� 
		scanf("%d",&enemy[i]);
		tmp-=enemy[i];
	}
	for(i=0;i<y;i++){ //ȸ�� ü�� �Է� 
		scanf("%d",&medi[i]);
		tmp+=medi[i];
	}
	if(tmp<=0){ //ȸ�� ü��+���� ü���� ������ ü�� �պ��� ���ų� ������ ���̱� 
		puts("0");
		return 0;
	}
	for(i=0;i<x+y;i++){
		if(idx1==x){ //���� ��� ���� 
			for(j=idx2;j<y;j++)
				printf("%d\n",j+1);
			break;
		}
		else if(idx2==y){ //���� ��� ���� 
			for(j=idx1;j<x;j++)
				printf("%d\n",(j+1)*-1);
			break;
		}
		if(val>m/2){ //���� ���� �� �ִ� ��� 
			val-=enemy[idx1++];
			printf("%d\n",idx1*-1);
		}
		else{ //ȸ������ �Ծ�� �ϴ� ��� 
			val+=medi[idx2++];
			printf("%d\n",idx2);
		}
	}
	return 0;
}

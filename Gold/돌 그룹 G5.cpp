#include <stdio.h>
#include <algorithm>
int check[1501][1501]={0,};
void DFS(int n1,int n2,int n3){
	int i,j,x,y,z;
	int arr[3];
	if(n1==n2&&n2==n3){
		printf("1\n");
		exit(0);
	}
	arr[0]=n1;
	arr[1]=n2;
	arr[2]=n3;
	for(i=0;i<3;i++){ //3���� 2���� ���� 
		for(j=i+1;j<3;j++){
			if(arr[i]<arr[j]){ //x,y ���� 
				x=i;
				y=j;
			}
			else if(arr[j]<arr[i]){
				x=j;
				y=i;
			}
			else
				continue;
				
			z=arr[3-(x+y)];
			y=arr[y]-arr[x]; //y=y-x 
			x=arr[x]*2; //x=x*2
			if(check[x][y]==0){ //���ݱ��� �������� ���� ��� ���� ǥ�� �� ���ȣ�� 
				check[x][y]=1;
				DFS(x,y,z);
			}	
			
		}
	}
}
int main(void){
	int n1,n2,n3,sum;
	scanf("%d%d%d",&n1,&n2,&n3);
	sum=n1+n2+n3;
	if(sum%3!=0){ //������ 3�ǹ���� �ƴ� ��� x 
		printf("0\n");
		return 0;
	}
	DFS(n1,n2,n3);
	printf("0\n");
	return 0;
}

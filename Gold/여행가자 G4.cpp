#include <stdio.h>
int arr[201];
int Find(int n){
	if(arr[n]==n)
		return n;
	else
		return arr[n]=Find(arr[n]);	
}
void Union(int n,int m){
	int a,b;
	a=Find(n);
	b=Find(m);
	if(a==b) //���� �����϶��� union x 
		return;
	arr[a]=b;
}
int main(void){
	int n,m,i,j,tmp,cur;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) //���չ迭 �ʱ�ȭ 
		arr[i]=i;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&tmp);
			if(tmp==1) //������ �������� 
				Union(i,j);
		}
	}
	scanf("%d",&tmp);
	for(i=1;i<m;i++){ //���� ���� ���� �˻� 
		scanf("%d",&cur);
		if(Find(tmp)!=Find(cur)) //���� �ٸ� �����̸� �Ұ��� 
			break;
	}
	if(i<m)
		puts("NO");
	else
		puts("YES");
	return 0;
}

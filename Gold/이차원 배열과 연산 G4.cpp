#include <stdio.h>
#include <algorithm> 
#include <vector>
using namespace std;
bool cmp(const pair<int,int> &p1,const pair<int,int> &p2){
	if(p1.second!=p2.second) //����Ƚ�� ������ ����
		return p1.second<p2.second;
	else //���� ũ�� ������ ����
		return p1.first<p2.first;
}
int main(void){
	int i,j,r,c,k,cur,idx,_max,res=-1,sec=0,col=3,row=3,arr[100][100];
	scanf("%d%d%d",&r,&c,&k);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&arr[i][j]);
			
	while(1){
		if(arr[r-1][c-1]==k){ //���� �˻� 
			res=sec;
			break;
		}
		if(sec==100) //100�ʰ� �ƴµ� ��ã������ ���� 
			break;
		_max=0;
		if(row>=col){ //R ���� 
			for(i=0;i<row;i++){
				vector<pair<int,int> >check(100); //(����,����Ƚ��)�� �����ϴ� ����
				idx=100;
				cur=0;
				for(j=0;j<col;j++){
					if(arr[i][j]==0)
						continue;
					if(check[arr[i][j]-1].first==0) //���� ���ٵ��� ���� �� ������ ���� 
						idx--; 
					check[arr[i][j]-1]=make_pair(arr[i][j],check[arr[i][j]-1].second+1); //���� �����Ϳ� ���� 
					arr[i][j]=0;
				}
				sort(check.begin(),check.end(),cmp); //�켱������ ���� ����
				for(j=idx;j<100;j++){ //���� ���ο� �����͸� �Է� 
					if(cur==100)
						break;
					arr[i][cur]=check[j].first;
					arr[i][cur+1]=check[j].second;
					cur+=2;
				}
				if(cur>_max) //�ִ� �� �˻� 
					_max=cur; 
			}
			col=_max; //�ִ� �� ������Ʈ 
		}
		else{ //C ���� 
			for(i=0;i<col;i++){
				vector<pair<int,int> >check(100); //(����,����Ƚ��)�� �����ϴ� ����
				idx=100;
				cur=0;
				for(j=0;j<row;j++){
					if(arr[j][i]==0)
						continue;
					if(check[arr[j][i]-1].first==0) //���� ���ٵ��� ���� �� ������ ���� 
						idx--; 
					check[arr[j][i]-1]=make_pair(arr[j][i],check[arr[j][i]-1].second+1); //���� �����Ϳ� ����
					arr[j][i]=0;
				}
				sort(check.begin(),check.end(),cmp); //�켱������ ���� ����
				for(j=idx;j<100;j++){ //�࿡ ���ο� �����͸� �Է� 
					if(cur==100)
						break;
					arr[cur][i]=check[j].first;
					arr[cur+1][i]=check[j].second;
					cur+=2;
				}
				if(cur>_max) //�ִ� �� �˻� 
					_max=cur; 
			}
			row=_max; //�ִ� �� ������Ʈ 
		}
		sec++;
	}
	printf("%d\n",res);
	return 0;
}

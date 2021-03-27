#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int main(void){
	int i,j,n,apple,r,c,m,s,x,y,cur=1,res=0,idx=0;
	int info[4][2]={{-1,0},{0,1},{1,0},{0,-1}}; //��->��->��->�� ���� ���� ���� 
	char d;
	queue<pair<int,int> >que;
	scanf("%d",&n);
	vector<vector<int> >map(n,vector<int>(n));
	scanf("%d",&apple);
	for(i=0;i<apple;i++){ //��� ��ġ ���� �Է� 
		scanf("%d%d",&r,&c);
		map[r-1][c-1]=1;
	}
	scanf("%d",&m);
	vector<pair<int,char> >rotate(m);
	for(i=0;i<m;i++){ //���� ��ȯ ���� �Է� 
		scanf("%d %c",&s,&d);
		getchar();
		rotate[i]=make_pair(s,d);
	}
	//���� ���� ���� ���� 
	i=j=0;
	map[0][0]=2;
	que.push(make_pair(0,0));
	while(1){
		//��ĭ �̵�
		res++;
		i+=info[cur][0];
		j+=info[cur][1];
		if(i<0||i>n-1||j<0||j>n-1) //���� �ε��� ��� ���� 
			break;
		if(map[i][j]==2) //�ڽ��� ���� �ε��� ��� ���� 
			break;
		if(map[i][j]==0){ //���ο� ĭ�� ����� �������� ����ĭ�� ���� 
			x=que.front().first;
			y=que.front().second;
			que.pop();
			map[x][y]=0;
		}
		//���ο� ĭ ������Ʈ 
		que.push(make_pair(i,j)); 
		map[i][j]=2;
		if(res==rotate[idx].first){ //������ȯ�ϴ� ��� 
			if(rotate[idx].second=='L'){ //�������� ȸ�� 
				cur--;
				if(cur<0)
					cur=3;
			}
			if(rotate[idx].second=='D'){ //���������� ȸ�� 
				cur++;
				if(cur>3)
					cur=0;
			}
			idx++;
		}
	}
	printf("%d\n",res);
	return 0;
}

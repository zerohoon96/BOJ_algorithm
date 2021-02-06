#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int r,c,i,j,k,x,y,tmp,tail=0,cur_x,cur_y,mini,index=0;
	bool flag=true;
	char ch,way[100];
	vector<pair<int,int> > move(10);
	vector<pair<int,int> > Rpos;
	move[1]=make_pair(1,-1);
	move[2]=make_pair(1,0);
	move[3]=make_pair(1,1);
	move[4]=make_pair(0,-1);
	move[5]=make_pair(0,0);
	move[6]=make_pair(0,1);
	move[7]=make_pair(-1,-1);
	move[8]=make_pair(-1,0);
	move[9]=make_pair(-1,1);
	
	scanf("%d%d",&r,&c);
	scanf("%c",&ch);
	vector<vector<int> >arr(r,vector<int>(c));
	for(i=0;i<r;i++){ //���� ���� ������ �Է¹��� 
		for(j=0;j<c;j++){
			scanf("%c",&ch);
			if(ch=='I'){
				cur_x=i;
				cur_y=j;
				arr[i][j]=2;
			}
			else if(ch=='R'){
				Rpos.push_back(make_pair(i,j));
				tail++;
				arr[i][j]=1;
			}
		}
		scanf("%c",&ch);
	}
	scanf("%s",way);
	for(i=0;i<strlen(way);i++){ //�Ѵܰ辿 ���� 
		tmp=way[i]-48;
		cur_x+=move[tmp].first;
		cur_y+=move[tmp].second;
		if(arr[cur_x][cur_y]==1){ //�̵��Ϸ��� ��ġ�� ��ģ �Ƶ��̳� 
			flag=false;
			break;
		}
		arr=vector<vector<int> >(r,vector<int>(c)); //�迭 �ʱ�ȭ 
		arr[cur_x][cur_y]=2; //��ġ ����
	 
		for(j=0;j<tail;j++){ //R��ġ ������Ʈ. ���߿� I ��ġ�� �������� ��
			x=Rpos[j].first;
			y=Rpos[j].second;
			mini=2147000000;
			for(k=1;k<10;k++){ //���� �̵���ġ find 
				tmp=abs(x+move[k].first-cur_x)+abs(y+move[k].second-cur_y);
				if(tmp<mini){
					mini=tmp;
					index=k;
				}
			}
			x+=move[index].first;
			y+=move[index].second;
			if(mini==0){ //��ģ �Ƶ��̳밡 ���Ӱ� �̵��� ��ġ�� ��ġ�� ��� 
				flag=false;
				break;
			}
			
			Rpos[j]=make_pair(x,y); //���ο� ��ġ ������Ʈ 
			arr[x][y]++;
		}
		if(!flag)
			break;
		sort(Rpos.begin(),Rpos.end());
		for(j=0;j<tail;j++){ //��ģ �Ƶ��̳��� ��ġ �ߺ� �˻� 
			x=Rpos[j].first;
			y=Rpos[j].second;
			if(arr[x][y]>1){
				for(k=0;k<arr[x][y];k++)
					Rpos.erase(Rpos.begin()+j);
				tail-=arr[x][y];
				arr[x][y]=0;
				j--;
			} 
		} 
	}
	
	if(!flag)
		printf("kraj %d\n",i+1);
	else{ 
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(arr[i][j]==0)
					printf(".");
				else if(arr[i][j]==1)
					printf("R");
				else
					printf("I");
			}
			puts("");
		}
	}
	return 0;
}

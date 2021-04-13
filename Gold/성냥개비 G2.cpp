#include <stdio.h>
#include <vector>
using namespace std;

int match[8]={0,0,1,7,4,2,0,8};
vector<vector<int> > dp(100,vector<int>()); //�� �ܰ迡 ������ ������ ���� 
bool comp_min(vector<int> a,vector<int> b){ //�� ���͸� ���ϴ� �Լ� 
	int i,size_1,size_2;
	size_1=(int)a.size();
	size_2=(int)b.size();
	if(size_1<size_2)
		return true;
	else if(size_1>size_2)
		return false;
	else{
		for(i=size_1-1;i>=0;i--){
			if(a[i]<b[i])
				return true;
			else if(a[i]>b[i])
				return false;
		}
	}
}

vector<int> stick_min(int remain){ //�ּڰ��� ��� ����Լ� 
	int i,tmp_remain;
	vector<int> res;
	if(remain==0) //0���� ���� ��� �� ���� ���� 
		return res;

	for(i=2;i<8;i++){ //���� 2~7���� �Һ��ϴ� ��츦 ������ Ž��
		vector<int> num;
		tmp_remain=remain-i;
		if(tmp_remain<0||tmp_remain==1) //���� ����� ���� ���ɰ��� ��ȿ���� ���� ��� continue 
			continue;
		
		if(tmp_remain==0&&i==6) //���ڰ� 0���� ������ �� �����Ƿ� �������� ��� 0���� �ٷ� ū ���� 6�� ��� 
			num.push_back(6);
		else
			num.push_back(match[i]);

		if(dp[tmp_remain].empty()) //dp�� �ִ� ���� ���� 
			dp[tmp_remain]=stick_min(tmp_remain);
		num.insert(num.end(),dp[tmp_remain].begin(),dp[tmp_remain].end());

		if(res.empty()||comp_min(num,res)) //���� ���ؼ� �ּڰ� ������Ʈ 
			res=num;
	}
	return res;
}

int main(void){
	int i,j,tc,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		vector<int> res;
		scanf("%d",&tc);
		
        //�ּڰ� Ž�� 
		res=stick_min(tc);
		for(j=(int)res.size()-1;j>=0;j--)
			printf("%d",res[j]);
		printf(" ");
		
		//�ִ� Ž�� (�ڸ����� �ִ��� �ø�)
		if(tc%2==0){ //¦���� ���� 1 ��� 
			for(j=0;j<tc/2;j++)
				printf("1");
		}
		else{ //Ȧ���� 7�� ����ϰ� ������ ���ɰ���� ��� 1�� ��� 
			printf("7");
			for(j=0;j<tc/2-1;j++)
				printf("1");
		}
		puts("");
	}
	return 0;
}

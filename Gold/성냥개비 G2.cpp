#include <stdio.h>
#include <vector>
using namespace std;

int match[8]={0,0,1,7,4,2,0,8};
vector<vector<int> > dp(100,vector<int>()); //현 단계에 있을때 최저인 숫자 
bool comp_min(vector<int> a,vector<int> b){ //두 백터를 비교하는 함수 
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

vector<int> stick_min(int remain){ //최솟값을 얻는 재귀함수 
	int i,tmp_remain;
	vector<int> res;
	if(remain==0) //0개가 남은 경우 빈 백터 리턴 
		return res;

	for(i=2;i<8;i++){ //성냥 2~7개를 소비하는 경우를 나누어 탐색
		vector<int> num;
		tmp_remain=remain-i;
		if(tmp_remain<0||tmp_remain==1) //새로 계산한 남은 성냥개비가 유효하지 않은 경우 continue 
			continue;
		
		if(tmp_remain==0&&i==6) //숫자가 0으로 시작할 수 없으므로 마지막인 경우 0보다 바로 큰 값인 6을 사용 
			num.push_back(6);
		else
			num.push_back(match[i]);

		if(dp[tmp_remain].empty()) //dp에 있는 값과 병합 
			dp[tmp_remain]=stick_min(tmp_remain);
		num.insert(num.end(),dp[tmp_remain].begin(),dp[tmp_remain].end());

		if(res.empty()||comp_min(num,res)) //값을 비교해서 최솟값 업데이트 
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
		
        //최솟값 탐색 
		res=stick_min(tc);
		for(j=(int)res.size()-1;j>=0;j--)
			printf("%d",res[j]);
		printf(" ");
		
		//최댓값 탐색 (자릿수를 최대한 늘림)
		if(tc%2==0){ //짝수면 전부 1 출력 
			for(j=0;j<tc/2;j++)
				printf("1");
		}
		else{ //홀수면 7을 출력하고 나머지 성냥개비는 모두 1에 사용 
			printf("7");
			for(j=0;j<tc/2-1;j++)
				printf("1");
		}
		puts("");
	}
	return 0;
}

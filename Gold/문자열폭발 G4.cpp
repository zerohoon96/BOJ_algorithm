#include <stdio.h>
#include <vector>
using namespace std;
vector<char> str,exp;
int main(void){
	int i,j,n,index=0;
	char tmp;
	bool detected=true;
	while(1){
		scanf("%c",&tmp);
		if(tmp=='\n')
			break;
		str.push_back(tmp);
	}
	while(1){
		scanf("%c",&tmp);
		if(tmp=='\n')
			break;
		exp.push_back(tmp);
	}
	vector<char> res(str.size()); //결과 저장할 백터 
	for(i=0;i<str.size();i++){
		res[index++]=str[i];
		if(index>=exp.size()&&res[index-1]==exp[exp.size()-1]){ //폭발문자열 의심되면 검사(폭발문자열의 마지막 문자가 같음) 
			n=0;
			detected=true;
			for(j=index-exp.size();j<=index-2;j++){ //폭발문자열 여부 검사 
				if(res[j]!=exp[n++]){
					detected=false;
					break;
				}
			}
			if(detected) //폭발 문자열을 발견했으면 덮어쓰기 
				index-=exp.size();
		} 
	}
	
	if(index==0) //결과 출력 
		printf("FRULA\n");
	else
		for(i=0;i<index;i++)
			printf("%c",res[i]);
	return 0;
}

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
	vector<char> res(str.size()); //��� ������ ���� 
	for(i=0;i<str.size();i++){
		res[index++]=str[i];
		if(index>=exp.size()&&res[index-1]==exp[exp.size()-1]){ //���߹��ڿ� �ǽɵǸ� �˻�(���߹��ڿ��� ������ ���ڰ� ����) 
			n=0;
			detected=true;
			for(j=index-exp.size();j<=index-2;j++){ //���߹��ڿ� ���� �˻� 
				if(res[j]!=exp[n++]){
					detected=false;
					break;
				}
			}
			if(detected) //���� ���ڿ��� �߰������� ����� 
				index-=exp.size();
		} 
	}
	
	if(index==0) //��� ��� 
		printf("FRULA\n");
	else
		for(i=0;i<index;i++)
			printf("%c",res[i]);
	return 0;
}

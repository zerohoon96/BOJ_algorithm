#include <stdio.h>
#include <string.h>
char arr[1000000];
int main(void){
	int i,len,ct=0,remain=0;
	bool flag=false;
	scanf("%s",arr);
	len=strlen(arr);
	for(i=0;i<strlen(arr);i++){ 
		if(ct==0){ //초기상태 
			if(arr[i]=='P'){ //P
				if(strlen(arr)==1) //P도 PPAP 문자열 
					flag=true;
				ct++;
			}
			else //A
				break;
			continue;
		}
		if(ct==1){ //P 상태 
			if(arr[i]=='P') //PP
				ct++;
			else //PA
				break;
			continue;
		}
		if(ct==2){ //PP 상태 
			if(arr[i]=='A') //PPA
				ct++;
			else //PPP (앞 P 2개만 사용)
				remain++; //앞서있는 P의 개수 추가 
			continue;
		}
		if(ct==3){ //PPA 상태 
			if(arr[i]=='P'){ //PPAP
				if(len==4){ //성공 
					flag=true;
					break;
				}
				len-=3;
				if(remain>0){ //앞서 있는 P가 1개 이상이면 PP로 설정 
					ct=2;
					remain--;
				}
				else //앞서 있는 P가 없으면 P 상태로 설정 
					ct=1;
			}
			else //PPAA
				break;
			continue;
		}
	}
	if(flag)
		puts("PPAP");
	else
		puts("NP");
	return 0;
}

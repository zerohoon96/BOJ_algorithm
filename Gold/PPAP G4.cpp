#include <stdio.h>
#include <string.h>
char arr[1000000];
int main(void){
	int i,len,ct=0,remain=0;
	bool flag=false;
	scanf("%s",arr);
	len=strlen(arr);
	for(i=0;i<strlen(arr);i++){ 
		if(ct==0){ //�ʱ���� 
			if(arr[i]=='P'){ //P
				if(strlen(arr)==1) //P�� PPAP ���ڿ� 
					flag=true;
				ct++;
			}
			else //A
				break;
			continue;
		}
		if(ct==1){ //P ���� 
			if(arr[i]=='P') //PP
				ct++;
			else //PA
				break;
			continue;
		}
		if(ct==2){ //PP ���� 
			if(arr[i]=='A') //PPA
				ct++;
			else //PPP (�� P 2���� ���)
				remain++; //�ռ��ִ� P�� ���� �߰� 
			continue;
		}
		if(ct==3){ //PPA ���� 
			if(arr[i]=='P'){ //PPAP
				if(len==4){ //���� 
					flag=true;
					break;
				}
				len-=3;
				if(remain>0){ //�ռ� �ִ� P�� 1�� �̻��̸� PP�� ���� 
					ct=2;
					remain--;
				}
				else //�ռ� �ִ� P�� ������ P ���·� ���� 
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

#include <stdio.h>
#include <string.h>
int main(void){
	char str[50],op[50];
	int num[50];	
	int i,j,idx1=0,idx2=0,sum=0,tmp=0;
	scanf("%s",&str);
	
	for(i=0;i<strlen(str);i++){ //����,������ �и� ���� 
		if(str[i]>=48&&str[i]<=57)
			tmp=tmp*10+str[i]-48;
		else{
			num[idx1++]=tmp;
			tmp=0;
			op[idx2++]=str[i];
		}
	}
	num[idx1++]=tmp;
	
	sum=num[0];
	for(i=1;i<idx1;i++){
		if(op[i-1]=='+'){ //+�������� ��� ���ϱ� ���� 
			sum+=num[i];
		}
		else if(op[i-1]=='-'){ //-�������� ��� ���� ���� 
			sum-=num[i];
			for(j=i;j<idx2;j++){ //���� -�� ������ �� ��� +�� -�� �ٲپ� ���� 
				if(op[j]=='-')
					break;
				sum-=num[j+1];
			}
			i=j;
		}
	}
	printf("%d\n",sum);
	return 0;
}

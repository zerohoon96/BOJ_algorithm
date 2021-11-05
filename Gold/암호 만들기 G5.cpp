#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> res;
vector<char> val;
vector<bool> check;
int n,m;
char cur; //지정된 현재 모음
string str;
void get_res(int ct1,int ct2,int ct3,int idx){ //현재 문자 개수, 지정 모음 잔여 개수, 자음 잔여 개수
    int i,tmp_ct2,tmp_ct3;
    if(ct1==n){ //n개의 문자를 조건에 맞게 사용했을때 검사
        if(ct2<=0&&ct3<=0)
            res.push_back(str);
        return;
    }
    for(i=idx;i<m;i++){ //순서대로 쌓기 위해 idx부터 시작
        tmp_ct2=ct2;
        tmp_ct3=ct3;
        if(val[i]=='a'||val[i]=='e'||val[i]=='i'||val[i]=='o'||val[i]=='u'){ //모음의 경우
            if(check[i]) //이미 지정됐던 모음
                continue;
            if(val[i]==cur){ //지정한 모음이고 아직 사용하지 않은 경우 사용
                if(ct2==0)
                    continue;
                tmp_ct2--;
            }
        }
        else //자음이면 자음 사용 횟수 감소
            tmp_ct3--;
        str.push_back(val[i]);
        get_res(ct1+1,tmp_ct2,tmp_ct3,i+1);
        str.pop_back();
    }
}
int main(void){
    int i;
    char c;
    scanf("%d%d",&n,&m);
    scanf("%c",&c);
    check.resize(m,false);
    for(i=0;i<m;i++){
        scanf("%c",&c); //알파벳 입력
        if(c==' '){
            i--;
            continue;
        }
        val.push_back(c);
    }
    sort(val.begin(),val.end());
    for(i=0;i<m;i++){ //모음 선정
        if(val[i]=='a'||val[i]=='e'||val[i]=='i'||val[i]=='o'||val[i]=='u'){
            cur=val[i];
            get_res(0,1,2,0);
            check[i]=true;
        }
    }
   sort(res.begin(),res.end());
    for(i=0;i<(int)res.size();i++)
        printf("%s\n",res[i].c_str());
    return 0;
}
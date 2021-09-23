#include <iostream>
#include <string>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n,s,i,res=0,ct=0;
    bool isCount=false;
    string str;
    cin>>n>>s;
    cin>>str;

    for(i=0;i<s-1;i++){
        if(!isCount){ //현재 카운트 중이 아닌 경우
            if(str[i]=='I')
                isCount=true;
            continue;
        }
        if(str[i]=='O'&&str[i+1]=='I'){ //OI 패턴 발견
            ct++;
            if(ct==n){ //현재 OI 횟수가 s와 동일
                res++;
                ct--;
            }
            i++; //2칸 이동
        }
        else{ //OI 패턴 발견 실패 (count 횟수, isCount 초기화)
            ct=0;
            if(str[i]=='O'||str[i+1]=='I') //다음 나오는 문제에 따라 isCount 초기화
                isCount=false;
        }
    }
    cout<<res;
    return 0;
}
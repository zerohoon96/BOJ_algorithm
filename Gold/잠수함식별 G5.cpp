#include <iostream>
#include <string>
using namespace std;
string str;
bool get_res(int i,int zero_ct,int one_ct,int state){
    if(i==(int)str.size()){ //문제 없이 마지막에 도달했으면 성공
        if(state==0||(state==1&&one_ct>0))
            return true;
        else
            return false;
    }
    if(state==0){ //초기 조건 분기
        if(str[i]=='1')
            return get_res(i+1,0,0,1);
        else
            return get_res(i+1,0,0,2);
    }
    if(state==1){ //첫번째 상태
        if(str[i]=='0'){
            if(one_ct>0){ //조건1 종료
                bool res1=false,res2=false;
                if(one_ct>1)
                    res1=get_res(i-1,zero_ct,one_ct,0);
                res2=get_res(i,zero_ct,one_ct,0);
                return res1||res2;
            }
            return get_res(i+1,zero_ct+1,one_ct,state);
        }
        else{
            if(zero_ct<2) //조건1 실패
                return false;
            return get_res(i+1,zero_ct,one_ct+1,state);
        }
    }
    else{ //두 번째 상태
        if(str[i]!='1') //조건2 실패
            return false;
        return get_res(i+1,zero_ct,one_ct,0);
    }
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    while(getline(cin,str)){
        if((int)str.size()==0)
            break;
        if(get_res(0,0,0,0))
            cout<<"SUBMARINE\n";
        else
            cout<<"NOISE\n";
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
string str;
bool is_palin(){
    int left,right;
    left=0;
    right=(int)str.size()-1;
    while(left<=right){ //회문 검사
        if(str[left++]!=str[right--])
            return false;
    }
    return true;
}
bool can_palin(int left,int right,bool can_skip){ //유사회문을 찾는 함수
    if(left>right)
        return true;
    if(str[left]!=str[right]){
        if(!can_skip)
            return false;
        return can_palin(left+1,right,false)||can_palin(left,right-1,false);
    }
    else
        return can_palin(left+1,right-1,can_skip);
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>str;
        if(is_palin()){
            cout<<'0'<<'\n';
            continue;
        }
        if(can_palin(0,(int)str.size()-1,true)) //유사 회문인 경우
            cout<<'1'<<'\n';
        else //회문, 유사 회문 모두 아님
            cout<<'2'<<'\n';
    }
    return 0;
}
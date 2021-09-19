#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    string str;
    while(1){
        stack<char> sta;
        getline(cin,str);
        if((int)str.size()==1&&str[0]=='.')
            break;
        for(i=0;i<(int)str.size();i++){
            if(str[i]=='('||str[i]=='[') //push
                sta.push(str[i]);
            else if(str[i]==')'||str[i]==']'){ //pop
                if((int)sta.size()<1)
                    break;
                if(str[i]==')'&&sta.top()!='(')
                    break;
                if(str[i]==']'&&sta.top()!='[')
                    break;
                sta.pop();
            }
            else if(str[i]=='.'&&(int)sta.size()>0)
                break;
        }
        if(i<(int)str.size())
            cout<<"no"<<'\n';
        else
            cout<<"yes"<<'\n';
    }
    return 0;
}
/*
 * 1. ( or [ 받으면 stack에 push
 * 2. ) or ] 받으면 pop 시도. size가 0이거나 top이 ( 일때 ), [ 일때 ] 가 아니면 no
 * 3. . 받으면 스택의 크기를 보고 크기가 0이 아니면 no
 * 4. 모든 조건 만족하면 yes
*/
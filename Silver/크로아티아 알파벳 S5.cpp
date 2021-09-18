#include <iostream>
#include <string>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int i,ct=0;
    cin>>str;

    for(i=0;i<(int)str.size();i++){
        ct++;
        if(str[i]=='c'){
            if(i+1<(int)str.size()&&(str[i+1]=='='||str[i+1]=='-'))
                i++;
        }
        else if(str[i]=='d'){
            if(i+2<(int)str.size()&&str[i+1]=='z'&&str[i+2]=='=')
                i+=2;
            else if(i+1<(int)str.size()&&str[i+1]=='-')
                i++;
        }
        else if(str[i]=='l'){
            if(i+1<(int)str.size()&&str[i+1]=='j')
                i++;
        }
        else if(str[i]=='n'){
            if(i+1<(int)str.size()&&str[i+1]=='j')
                i++;
        }
        else if(str[i]=='s'||str[i]=='z'){
            if(i+1<(int)str.size()&&str[i+1]=='=')
                i++;
        }
    }
    cout<<ct;
    return 0;
}
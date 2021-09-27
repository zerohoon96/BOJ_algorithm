#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    char tmp;
    cin>>s1;
    cin>>s2;
    while(1){
        if(s1==s2){
            cout<<'1';
            break;
        }
        if(s1.length()>=s2.length()){
            cout<<'0';
            break;
        }
        tmp=s2[s2.length()-1];
        s2.pop_back();
        if(tmp=='B')
            reverse(s2.begin(),s2.end());
    }
    return 0;
}
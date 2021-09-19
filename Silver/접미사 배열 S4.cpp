#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    string str;
    vector<string> vec;
    cin>>str;
    for(i=0;i<(int)str.size();i++)
        vec.push_back(str.substr(i,str.size()-i));
    sort(vec.begin(),vec.end());
    for(i=0;i<(int)vec.size();i++)
        cout<<vec[i]<<'\n';
    return 0;
}
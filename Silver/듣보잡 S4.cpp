#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i;
    map<string,bool> my_map;
    vector<string> vec;
    string str;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>str;
        my_map.insert(make_pair(str,true));
    }
    for(i=0;i<m;i++){
        cin>>str;
        if(my_map.find(str)!=my_map.end())
            vec.push_back(str);
    }
    sort(vec.begin(),vec.end());
    cout<<vec.size()<<'\n';
    for(i=0;i<(int)vec.size();i++)
        cout<<vec[i]<<'\n';
    return 0;
}
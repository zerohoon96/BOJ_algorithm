#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(4);
    cout<<fixed;
    int ct=0;
    map<string,int> trees;
    map<string,int>::iterator iter;
    string str;
    while(1){
        getline(cin,str);
        if(str.size()==0)
            break;
        if(trees.count(str)<1)
            trees.insert(make_pair(str,1));
        else
            trees[str]++;
        ct++;
    }
    for(iter=trees.begin();iter!=trees.end();iter++)
        cout<<iter->first<<' '<<(double)iter->second/ct*100<<'\n';
    return 0;
}
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,ct=0;
    int arr[26];
    string str;
    cin>>n;
    for(i=0;i<n;i++){
        memset(arr,0,sizeof(int)*26);
        cin>>str;
        for(j=0;j<(int)str.size();j++){
            arr[str[j]-97]++;
            if(j==0)
                continue;
            if(arr[str[j]-97]>1&&str[j]!=str[j-1])
                break;
        }
        if(j==(int)str.size())
            ct++;
    }
    cout<<ct;
    return 0;
}
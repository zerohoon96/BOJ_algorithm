#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int n,m,i,j,k;
    cin>>n;
    for(i=0;i<n;i++){
        vector<string> phone;
        cin>>m;
        for(j=0;j<m;j++){
            cin>>str;
            phone.push_back(str);
        }
        sort(phone.begin(),phone.end()); //모든 번호 정렬
        for(j=0;j<m-1;j++){
            if((int)phone[j].size()>=(int)phone[j+1].size()) //다음 번호보다 같거나 크면 두 번호는 무조건 일관성이 있음
                continue;
            for(k=0;k<(int)phone[j].size();k++){ //현재 번호와 다음 번호를 비교
                if(phone[j][k]!=phone[j+1][k])
                    break;
            }
            if(k==(int)phone[j].size()) //모든 원소가 같으면 종료
                break;
        }
        if(j<m-1) //중간에 종료된 경우 일관성이 없음
            cout<<"NO"<<'\n';
        else
            cout<<"YES"<<'\n';
    }
    return 0;
}
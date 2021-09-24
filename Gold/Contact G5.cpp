#include <iostream>
#include <string>
using namespace std;
string str;
int zero_ct=0,one_ct=0;
bool get_res(int state,int cur){
    if(cur==(int)str.size()){
        if((state==1&&one_ct<1)||state==2) //첫 번째 패턴에서 1로 끝나지 않음 or 두 번째 패턴이 끝나지 않음
            return false;
        else
            return true;
    }
    if(state==0){ //패턴 시작 체크
        if(str[cur]=='1'){
            zero_ct=one_ct=0;
            return get_res(1,cur+1);
        }
        else
            return get_res(2,cur+1);
    }
    else if(state==1){ //첫 번째 패턴
        if(str[cur]=='0'){
            if(one_ct>0){ //첫 번째 패턴 종료 (조건 충족 후 0 등장)
                bool res=false;
                if(one_ct>1)
                    res=get_res(0,cur-1);
                return res||get_res(2,cur+1);
            }
            zero_ct++;
        }
        else{
            if(zero_ct<2) //1이 등장하기 전에 0이 충분히 쌓이지 않음
                return false;
            one_ct++;
        }
        return get_res(1,cur+1);
    }
    else{ //두 번째 패턴
        if(str[cur]=='1')
            return get_res(0,cur+1);
        else
            return false;
    }
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>str;
        zero_ct=one_ct=0;
        if(get_res(0,0))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
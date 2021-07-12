#include <stdio.h>
#include <string>
#include <map>
using namespace std;
map<string,string> link;
map<string,int> check;
string Find(string str){ //Find 함수
    if(str.compare(link[str])==0)
        return str;
    else
        return link[str]=Find(link[str]);
}
int Union(string str1,string str2){ //Union 함수
    str1=Find(str1);
    str2=Find(str2);
    if(str1.compare(str2)==0) //같은 친구 네트워크인 경우 해당 네트워크의 현재값 리턴
        return check[str1];
    else{ //다른 친구 네트워크의 경우 병합
        link[str2]=str1;
        return check[str1]+=check[str2];
    }
}
void check_str(string str){ //새로 등장하는 친구의 경우 map에 추가 (중복이면 false로 추가 안됨)
    if(link.insert(make_pair(str,str)).second)
        check.insert(make_pair(str,1));
}
int main(void){
    int tc,n,i,j;
    char buf[20];
    string str1,str2;
    scanf("%d",&tc);
    for(i=0;i<tc;i++){ //입력받은 테스트 케이스 수만큼 진행
        scanf("%d",&n);
        link.clear();
        check.clear();
        for(j=0;j<n;j++){ //친구 관계 개수만큼 진행
            scanf("%s",buf);
            str1=buf;
            scanf("%s",buf);
            str2=buf;
            check_str(str1); //첫 등장 친구 검사
            check_str(str2);
            printf("%d\n",Union(str1,str2)); //Union과 동시에 결과 출력
        }
    }
    return 0;
}
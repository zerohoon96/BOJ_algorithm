#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
struct info{
    string cur;
    int zero,ct;
    info(string a,int b,int c){
        cur=a;
        zero=b;
        ct=c;
    }
};

int main(void){
    string cur,tmp;
    queue<info> que;
    map<string,int> check;
    int i,ct,res=-1,zero=0,num;
    char c;
    for(i=0;i<9;i++){
        scanf("%d",&num);
        cur.push_back(num+48);
        if(num==0)
            zero=i;
    }
    check.insert(make_pair(cur,1));
    que.push(info(cur,zero,0)); //초깃값 삽입

    while(!que.empty()){ //BFS
        cur=que.front().cur;
        zero=que.front().zero;
        ct=que.front().ct;
        que.pop();
        for(i=1;i<=8;i++){
            if(cur[i-1]!=i+48)
                break;
        }
        if(i>8){ //최소 이동 횟수를 구한 경우 종료
            res=ct;
            break;
        }
        c=cur[zero];
        if(zero>2){ //↑ 검사
            tmp=cur;
            tmp[zero]=tmp[zero-3];
            tmp[zero-3]=c;
            if(check.find(tmp)==check.end()){
                check[tmp]=1;
                que.push(info(tmp,zero-3,ct+1));
            }
        }

        if(zero<6){ //↓ 검사
            tmp=cur;
            tmp[zero]=tmp[zero+3];
            tmp[zero+3]=c;
            if(check.find(tmp)==check.end()){
                check[tmp]=1;
                que.push(info(tmp,zero+3,ct+1));
            }
        }
        
        if(zero%3>0){ //← 검사
            tmp=cur;
            tmp[zero]=tmp[zero-1];
            tmp[zero-1]=c;
            
            if(check.find(tmp)==check.end()){
                check[tmp]=1;
                que.push(info(tmp,zero-1,ct+1));
            }
        }
        
        if((zero+1)%3>0){ //→ 검사
            tmp=cur;
            tmp[zero]=tmp[zero+1];
            tmp[zero+1]=c;
            if(check.find(tmp)==check.end()){
                check[tmp]=1;
                que.push(info(tmp,zero+1,ct+1));
            }
        }
        
    }
    printf("%d\n",res); //결과 출력
    return 0;
}
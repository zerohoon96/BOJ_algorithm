#include <stdio.h>
#include <queue>
#include <string>
using namespace std;
vector<pair<int,char> > check; //방문 기록 저장
int main(void){
    int i,j,tc,init,num,target,cur;
    scanf("%d",&tc);
    for(i=0;i<tc;i++){
        scanf("%d%d",&init,&target);
        queue<int> que;
        vector<int> res;
        string str;
        check.resize(10000,make_pair(-1,0)); //방문 기록 저장
        que.push(init);
        while(!que.empty()){ //BFS
            cur=que.front();
            que.pop();
            if(cur==target) //목표값과 같으면 break
                break;
            num=cur*2>9999?(cur*2)%10000:cur*2; //D연산
            if(check[num].second==0){
                que.push(num);
                check[num].first=cur;
                check[num].second='D';
            }
            num=cur==0?9999:cur-1; //S연산
            if(check[num].second==0){
                que.push(num);
                check[num].first=cur;
                check[num].second='S';
            }
            if(cur==0) //0이면 L,R을 해도 그대로임
                continue;
            num=(cur*10+cur/1000)%10000; //L연산
            if(check[num].second==0){
                que.push(num);
                check[num].first=cur;
                check[num].second='L';
            }
            num=cur%10*1000+cur/10; //R연산
            if(check[num].second==0){
                que.push(num);
                check[num].first=cur;
                check[num].second='R';
            }
        }
        while(init!=target){ //역추적으로 경로 저장 후 출력
            res.push_back(check[target].second);
            target=check[target].first;
        }
        for(j=(int)res.size()-1;j>=0;j--)
            printf("%c",res[j]);
        puts("");
    }
    return 0;
}
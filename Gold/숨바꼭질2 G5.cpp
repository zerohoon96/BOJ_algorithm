#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
int main(void){
    int n,k,ct=0,pos,sec;
    vector<int> map;
    queue<pair<int,int>> que;
    scanf("%d%d",&n,&k);
    map.resize(100001,abs(n-k));
    que.push(make_pair(n,0));
    while(!que.empty()){
        pos=que.front().first;
        sec=que.front().second;
        que.pop();
        if(pos<0||pos>100000) //위치를 벗어나면 continue
            continue;
        if(map[pos]<sec) //유망하지 않으면 continue
            continue;
        map[pos]=sec;
        if(pos==k){
            ct++;
            continue;
        }
        que.push(make_pair(pos+1,sec+1));
        que.push(make_pair(pos-1,sec+1));
        que.push(make_pair(pos*2,sec+1));
    }
    printf("%d\n%d\n",map[k],ct);
    return 0;
}
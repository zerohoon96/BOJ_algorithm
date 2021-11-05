#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
struct info{
    int x,y,ct;
    info(int a,int b,int c){
        x=a;
        y=b;
        ct=c;
    }
};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,m,x,y,ct,tmp_x,tmp_y,res=0;
    int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<char> > map;
    vector<pair<int,int> > land;
    string str;
    cin>>n>>m;
    map.resize(n,vector<char>(m));
    for(i=0;i<n;i++){
        cin>>str;
        for(j=0;j<m;j++){
            if(str[j]=='L')
                land.push_back(make_pair(i,j));
            map[i][j]=str[j];
        }
    }
    for(i=0;i<(int)land.size();i++){
        queue<info> que;
        vector<vector<bool> > check(n,vector<bool>(m));
        que.push(info(land[i].first,land[i].second,0));
        check[land[i].first][land[i].second]=true;
        while(!que.empty()){
            x=que.front().x;
            y=que.front().y;
            ct=que.front().ct;
            que.pop();
            for(j=0;j<4;j++){
                tmp_x=x+direction[j][0];
                tmp_y=y+direction[j][1];
                if(tmp_x<0||tmp_x>n-1||tmp_y<0||tmp_y>m-1)
                    continue;
                if(map[tmp_x][tmp_y]=='W')
                    continue;
                if(check[tmp_x][tmp_y])
                    continue;
                check[tmp_x][tmp_y]=true;
                que.push(info(tmp_x,tmp_y,ct+1));
            }
        }
        if(ct>res)
            res=ct;
    }
    cout<<res;
    return 0;
}
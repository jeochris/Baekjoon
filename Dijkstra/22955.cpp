#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, M, stx, sty, edx, edy;
int arr[1003][1003];
vector<pair<pair<int,int>,int>> adj[1003][1003];
long long int dis[1003][1003], inf=9e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1;i<=N;i++){
        string line;
        cin >> line;
        for(int j=1;j<=M;j++){
            if(line[j-1]=='C'){
                arr[j][i]=5;
                stx=j; sty=i;
            }
            else if(line[j-1]=='E'){
                arr[j][i]=2;
                edx=j; edy=i;
            }
            else if(line[j-1]=='X') arr[j][i]=1;
            else if(line[j-1]=='F') arr[j][i]=3;
            else if(line[j-1]=='L') arr[j][i]=4;
            else arr[j][i]=6;
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int here=arr[j][i], below=arr[j][i+1], upper=arr[j][i-1];
            int lft=arr[j-1][i], rgt=arr[j+1][i];
            if(here==1){
                if(below==1) adj[j][i].push_back({{j,i+1},0});
                else if(below>=2 && below<=4) adj[j][i].push_back({{j,i+1},10});
            }
            else if(here<=5 && here>=3){
                if(below==4) adj[j][i].push_back({{j,i+1},5});
                if(lft>=1 && lft<=4) adj[j][i].push_back({{j-1,i},1});
                if(rgt>=1 && rgt<=4) adj[j][i].push_back({{j+1,i},1});
            }
            if(here==4){
                if(upper>=2 && upper<=4) adj[j][i].push_back({{j,i-1},5});
            }
        }
    }

    priority_queue<pair<long long int,pair<int,int>>> pq;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            dis[j][i]=inf;
        }
    }
    pq.push({0,{stx,sty}});
    dis[stx][sty]=0;

    while(!pq.empty()){
        auto [d,u]=pq.top();
        auto [x,y]=u;
        pq.pop();
        if(-d>dis[x][y]) continue;
        for(auto [v,c]:adj[x][y]){
            auto [nx,ny]=v;
            if(dis[nx][ny]>dis[x][y]+c){
                dis[nx][ny]=dis[x][y]+c;
                pq.push({-dis[nx][ny],{nx,ny}});
            }
        }
    }

    if(dis[edx][edy]==inf) cout << "dodo sad";
    else cout << dis[edx][edy];

}
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
vector<pair<pair<int,int>,int>> adj[502][502];
long long int dis[502][502], inf=9e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        string line;
        cin >> line;
        for(int j=0;j<M;j++){
            if(line[j]=='/'){
                adj[j][i].push_back({{j+1,i+1},1});
                adj[j+1][i+1].push_back({{j,i},1});
                adj[j][i+1].push_back({{j+1,i},0});
                adj[j+1][i].push_back({{j,i+1},0});
            }
            else{
                adj[j][i].push_back({{j+1,i+1},0});
                adj[j+1][i+1].push_back({{j,i},0});
                adj[j][i+1].push_back({{j+1,i},1});
                adj[j+1][i].push_back({{j,i+1},1});
            }
        }
    }

    priority_queue<pair<long long int,pair<int,int>>> pq;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++) dis[j][i]=inf;
    }
    pq.push({0,{0,0}});
    dis[0][0]=0;
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        auto [x,y]=u;
        if(-d>dis[x][y]) continue;
        for(auto [v,c]:adj[x][y]){
            auto [x1,y1]=v;
            if(dis[x1][y1]>dis[x][y]+c){
                dis[x1][y1]=dis[x][y]+c;
                pq.push({-dis[x1][y1],v});
            }
        }
    }
    if(dis[M][N]==inf) cout << "NO SOLUTION";
    else cout << dis[M][N];

}
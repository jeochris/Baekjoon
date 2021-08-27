#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
vector<pair<int,int>> adj[4002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }

    priority_queue<pair<long long int,int>> pq;
    long long int dis[4002], inf=2e18, dis2[4002][2];
    
    fill(dis+1,dis+N+1,inf);
    pq.push({0,1});
    dis[1]=0;
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(-d>dis[u]) continue;
        for(auto [v,c]:adj[u]){
            if(dis[v]>dis[u]+c){
                dis[v]=dis[u]+c;
                pq.push({-dis[v],v});
            }
        }
    }

    priority_queue<pair<long long int,pair<int,int>>> pq2;
    
    for(int i=1;i<=N;i++){
        dis2[i][0]=inf;
        dis2[i][1]=inf;
    }
    pq2.push({0,{1,1}});
    dis2[1][1]=0;
    while(!pq2.empty()){
        auto [d,t]=pq2.top(); pq2.pop();
        auto [u,x]=t;
        
        if(x==1 && -d>dis2[u][1]) continue;
        if(x==4 && -d>dis2[u][0]) continue;

        for(auto [v,c]:adj[u]){
            if(x==1){
                if(dis2[v][0]>dis2[u][1]+c){
                    dis2[v][0]=dis2[u][1]+c;
                    pq2.push({-dis2[v][0],{v,4}});
                }
            }
            else{
                if(dis2[v][1]>dis2[u][0]+c*4){
                    dis2[v][1]=dis2[u][0]+c*4;
                    pq2.push({-dis2[v][1],{v,1}});
                }
            }
        }
    }

    int ans=0;
    for(int i=2;i<=N;i++){
        if(dis[i]*2 < dis2[i][0] && dis[i]*2 < dis2[i][1]) ans++;
    }
    cout << ans;

}
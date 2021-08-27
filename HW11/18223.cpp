#include <iostream>
#include <queue>
using namespace std;

int V, E, P;
vector<pair<int,int>> adj[5003];

long long int dis[5003], dis2[5003], inf=2e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> P;
    for(int i=0;i<E;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    fill(dis+1,dis+V+1,inf);
    fill(dis2+1,dis2+V+1,inf);

    priority_queue<pair<int,int>> pq, pq2;
    
    pq.push({0,1});
    dis[1]=0;
    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();
        if(-d>dis[u]) continue;
        for(auto [v,c]:adj[u]){
            if(dis[v]>dis[u]+c){
                dis[v]=dis[u]+c;
                pq.push({-dis[v],v});
            }
        }
    }

    pq2.push({0,P});
    dis2[P]=0;
    while(!pq2.empty()){
        auto [d,u]=pq2.top();
        pq2.pop();
        if(-d>dis2[u]) continue;
        for(auto [v,c]:adj[u]){
            if(dis2[v]>dis2[u]+c){
                dis2[v]=dis2[u]+c;
                pq2.push({-dis2[v],v});
            }
        }
    }

    if(dis[V]==dis[P]+dis2[V]) cout << "SAVE HIM";
    else cout << "GOOD BYE";

}
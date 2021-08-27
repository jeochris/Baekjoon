#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;
long long int dis[200003], dis2[200003];
long long int inf=2e18;
vector<pair<int,int>> adj[200003];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for(int i=0;i<M;i++){
        int a,b,t;
        cin >> a >> b >> t;
        adj[a].push_back({b,t});
        adj[b].push_back({a,t});
    }

    fill(dis+1,dis+N+1,inf);
    fill(dis2+1,dis2+N+1,inf);

    priority_queue<pair<long long int,int>> pq, pq2;

    dis[1]=0;
    pq.push({0,1});

    for(int i=0;i<K;i++){
        int p;
        cin >> p;
        dis2[p]=0;
        pq2.push({0,p});
    }

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

    while(!pq2.empty()){
        auto [d,u]=pq2.top(); pq2.pop();
        if(-d>dis2[u]) continue;
        for(auto [v,c]:adj[u]){
            if(dis2[v]>dis2[u]+c){
                dis2[v]=dis2[u]+c;
                pq2.push({-dis2[v],v});
            }
        }
    }

    vector<int> ans;
    for(int i=2;i<=N;i++){
        if(dis[i]<dis2[i]) ans.push_back(i);
    }
    sort(ans.begin(),ans.end());

    if(ans.empty()) cout << 0;
    else{
        for(int x:ans) cout << x << " ";
    }

}
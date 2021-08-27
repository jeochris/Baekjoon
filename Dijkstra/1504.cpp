#include <iostream>
#include <queue>
using namespace std;

int N, E, v1, v2;
long long int dis1[802], dis2[802], big=2e18, ans=2e18;
vector<pair<int,int>> adj[802];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;
    for(int i=0;i<E;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    cin >> v1 >> v2;

    fill(dis1+1,dis1+N+1,big);
    fill(dis2+1,dis2+N+1,big);

    priority_queue<pair<long long int,int>> pq1, pq2;
    
    pq1.push({0,v1});
    dis1[v1]=0;
    while(!pq1.empty()){
        auto [d,u]=pq1.top();
        pq1.pop();
        if(-d>dis1[u]) continue;
        for(auto [v,c]:adj[u]){
            if(dis1[v]>dis1[u]+c){
                dis1[v]=dis1[u]+c;
                pq1.push({-dis1[v],v});
            }
        }
    }

    pq2.push({0,v2});
    dis2[v2]=0;
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

    if(dis1[1]!=big && dis1[v2]!=big && dis2[N]!=big){
        ans=dis1[1]+dis1[v2]+dis2[N];
    }
    if(dis2[1]!=big && dis2[v1]!=big && dis1[N]!=big){
        ans=min(ans,dis2[1]+dis2[v1]+dis1[N]);
    }
    if(ans==big) cout << -1;
    else cout << ans;

}
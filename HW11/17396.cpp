#include <iostream>
#include <queue>
using namespace std;

int N, M;
int cantGo[100003];
long long int big=1e18, dis[100003];
vector<pair<int,int>> adj[100002];
priority_queue<pair<long long int,int>> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> cantGo[i];
    for(int i=0;i<M;i++){
        int a,b,t;
        cin >> a >> b >> t;
        adj[a].push_back({b,t});
        adj[b].push_back({a,t});
    }

    fill(dis,dis+N,big);
    pq.push({0,0});
    dis[0]=0;

    while(!pq.empty()){
        long long int d=-pq.top().first;
        int u=pq.top().second;
        pq.pop();

        if(d>dis[u]) continue;
        for(auto [v,c]:adj[u]){
            if((v==(N-1) || !cantGo[v]) && dis[v]>dis[u]+c){
                dis[v]=dis[u]+c;
                pq.push({-dis[v],v});
            }
        }
    }

    if(dis[N-1]==big) cout << -1;
    else cout << dis[N-1];

}
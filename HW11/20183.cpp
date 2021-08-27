#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A, B;
vector<pair<int,int>> adj[100003];
long long int dis[100003], inf=9e18, C;

bool check(int avM){
    fill(dis+1,dis+N+1,inf);
    priority_queue<pair<long long int,int>> pq;
    pq.push({0,A});
    dis[A]=0;

    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(-d>dis[u]) continue;
        for(auto [v,c]:adj[u]){
            if(c<=avM && dis[v]>dis[u]+c){
                dis[v]=dis[u]+c;
                pq.push({-dis[v],v});
            }
        }
    }

    if(dis[B]>C) return false;
    else return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> A >> B >> C;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    int s=1, e=1e9, ans=1e9+1;
    while(s<=e){
        int mid=(s+e)/2;
        if(check(mid)){
            ans=min(ans,mid);
            e=mid-1;
        }
        else s=mid+1;
    }

    if(ans!=1e9+1) cout << ans;
    else cout << -1;

}
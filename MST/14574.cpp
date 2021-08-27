#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, p[1004], c[1004], parent[1004], height[1004];
bool visited[1004];

struct edge{
    int u,v,c;
    bool operator<(edge rhs){
        return c>rhs.c;
    }
};

vector<edge> E;
vector<int> adj[1004];

int Find(int x){
    if(parent[x]==-1) return x;
    return parent[x]=Find(parent[x]);
}

bool Union(int x,int y){
    int u=Find(x), v=Find(y);
    if(u==v) return false;
    if(height[u]<height[v]) swap(u,v);
    parent[v]=u;
    if(height[u]==height[v]) height[u]++;
    return true;
}

void dfs(int x){
    visited[x]=true;
    for(int u:adj[x]){
        if(!visited[u]){
            dfs(u);
            cout << x << " " << u << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1;i<=N;i++){
        parent[i]=-1;
        cin >> p[i] >> c[i];
    }

    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;j++){
            int watch=(c[i]+c[j])/abs(p[i]-p[j]);
            E.push_back({i,j,watch});
        }
    }

    sort(E.begin(),E.end());

    int cnt=0;
    long long int ans=0;
    for(auto e:E){
        int u=e.u, v=e.v, c=e.c;
        if(Union(u,v)){
            cnt++;
            ans+=c;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(cnt==N-1) break;
    }
    cout << ans << "\n";

    dfs(1);

}
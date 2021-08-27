#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans=0;
int parent[1003], height[1003];

struct edge{
    int u,v;
    int cost;
    bool operator<(edge rhs){
        return cost<rhs.cost;
    }
};

vector<edge> E;

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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1;i<=N;i++) parent[i]=-1;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        E.push_back({a,b,c});
    }

    sort(E.begin(),E.end());

    int cnt=0;
    for(auto e:E){
        int u=e.u, v=e.v, c=e.cost;
        if(Union(u,v)){
            ans+=c;
            cnt++;
        }
        if(cnt==N-1) break;
    }

    cout << ans;

}
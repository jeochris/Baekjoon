#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, parent[100003], height[100003];
long long int havingV[100003], ans=0;

struct edge{
    int u,v;
    int cost;
    bool operator<(edge rhs){
        return cost>rhs.cost;
    }
};

vector<edge> E;

int Find(int x){
    if(parent[x]==-1) return x;
    return parent[x]=Find(parent[x]);
}

void Union(int x,int y,int c){
    int u=Find(x), v=Find(y);
    if(height[u]<height[v]) swap(u,v);
    parent[v]=u;
    if(height[u]==height[v]) height[u]++;
    
    havingV[u]+=(havingV[v]+1);
    ans=max(ans,c*havingV[u]);
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1;i<=N;i++) parent[i]=-1;
    for(int i=0;i<N-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        E.push_back({a,b,c});
    }

    sort(E.begin(),E.end());

    for(int i=0;i<N-1;i++){
        Union(E[i].u,E[i].v,E[i].cost);
    }

    cout << ans;

}
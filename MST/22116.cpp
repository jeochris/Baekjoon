#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct edge{
    pair<int,int> u, v;
    int c;
    bool operator<(edge rhs){
        return c<rhs.c;
    }
};

int N, board[1003][1003], height[1003][1003];
vector<edge> E;
pair<int,int> parent[1003][1003];

pair<int,int> Find(pair<int,int> x){
    int u=x.first, v=x.second;
    if(parent[u][v]==x) return x;
    return parent[u][v]=Find(parent[u][v]);
}

bool Union(pair<int,int> x,pair<int,int> y){
    pair<int,int> u=Find(x), v=Find(y);
    if(u==v) return false;

    int x1=u.first, y1=u.second, x2=v.first, y2=v.second;
    if(height[x1][y1]<height[x2][y2]) swap(u,v);
    x1=u.first; y1=u.second; x2=v.first; y2=v.second;
    parent[x2][y2]=u;
    if(height[x1][y1]==height[x2][y2]) height[x1][y1]++;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> board[j][i];
            pair<int,int> u={j,i};
            parent[j][i]=u;
            if(i!=1){
                pair<int,int> v={j,i-1};
                E.push_back({u,v,abs(board[j][i]-board[j][i-1])});
            }
            if(j!=1){
                pair<int,int> v={j-1,i};
                E.push_back({u,v,abs(board[j][i]-board[j-1][i])});
            }
        }
    }

    sort(E.begin(),E.end());

    int idx=0, ans=0;
    while(Find({1,1})!=Find({N,N})){
        pair<int,int> u=E[idx].u, v=E[idx].v;
        if(Union(u,v)){
            ans=E[idx].c;
        }
        idx++;
    }
    cout << ans;

}
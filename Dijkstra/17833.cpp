#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, R, D, M;
vector<pair<int,int>> adj[2002];
long long int dis[2002], inf=9e18;
int tmpAdj[2002][2002], tmpInf=2e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> R >> D >> M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            tmpAdj[i][j]=tmpInf;
        }
    }

    for(int i=0;i<M;i++){
        int h, t, e1, e2;
        cin >> h >> t >> e1 >> e2;
        for(int j=0;j<=N-h;j++){
            int& ret=tmpAdj[e1+j][e2+j];
            ret=min(ret,t);
            tmpAdj[e2+j][e1+j]=ret;
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(tmpAdj[i][j]!=tmpInf){
                adj[i].push_back({j,tmpAdj[i][j]});
                adj[j].push_back({i,tmpAdj[i][j]});
            }
        }
    }

    priority_queue<pair<long long int,int>> pq;
    fill(dis+1,dis+N+1,inf);
    pq.push({0,R});
    dis[R]=0;
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

    if(dis[D]==inf) cout << -1;
    else cout << dis[D];

}
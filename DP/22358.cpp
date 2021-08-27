#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, M, K, S, T, visited[100002][11];
vector<pair<int,int>> adj[100002];
long long int dp[100002][11], ans=-1;

long long int getDP(int until,int lift){
    if(until<S && lift==0) return -1;
    if(lift<0) return -1;
    
    long long int& ret=dp[until][lift];
    if(until==S && lift==0) ret=0;
    if(ret!=-1 || visited[until][lift]) return ret;

    for(auto [v,c]:adj[until]){
        if(c>0){
            if(getDP(v,lift)!=-1) ret=max(ret,dp[v][lift]+c);
        }
        else{
            if(getDP(v,lift-1)!=-1) ret=max(ret,dp[v][lift-1]);
        }
    }
    visited[until][lift]=1;
    return ret;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K >> S >> T;
    for(int i=0;i<M;i++){
        int a,b,t;
        cin >> a >> b >> t;
        adj[b].push_back({a,t});
        adj[a].push_back({b,0});
    }

    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=K;i++) ans=max(ans,getDP(T,i));
    cout << ans;

}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int parent[30004], height[30004];
int havingVertex[30004], havingSum[30004];
vector<pair<int,int>> group;
int dp[3005][2], groupNum=0;

int Find(int x){
    if(parent[x]==-1) return x;
    return parent[x]=Find(parent[x]);
}

void Union(int x,int y){
    int u=Find(x),v=Find(y);
    if(u==v) return;

    if(height[u]<height[v]) swap(u,v);
    parent[v]=u;
    havingVertex[u]+=havingVertex[v];
    havingSum[u]+=havingSum[v];
    if(height[u]==height[v]) height[u]++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for(int i=1;i<=N;i++){
        parent[i]=-1;
        havingVertex[i]=1;
        int tmp;
        cin >> tmp;
        havingSum[i]=tmp;
    }

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }

    for(int i=1;i<=N;i++)if(parent[i]==-1){
        group.push_back({havingVertex[i],havingSum[i]});
        groupNum++;
    }

    for(int i=0;i<groupNum;i++){
        for(int j=1;j<K;j++){
            dp[j][1]=dp[j][0];
            if(group[i].first<=j) dp[j][1]=max(dp[j][1],dp[j-group[i].first][0]+group[i].second);
        }
        for(int j=1;j<K;j++) dp[j][0]=dp[j][1];
    }

    cout << dp[K-1][1];

}
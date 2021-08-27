#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, R, ans, giga, befgiga;
bool visited[200003];
vector<pair<int,int>> adj[200003];
queue<pair<int,int>> q;

int getColumn(int bef,int x){
    int sum=0, plus=0, next=0;
    for(int i=0;i<adj[x].size();i++){
        if(adj[x][i].first!=bef){
            sum++;
            next=adj[x][i].first;
            plus=adj[x][i].second;
        }
    }
    if(sum==1){
        return plus+getColumn(x,next);
    }
    else{
        giga=x;
        befgiga=bef;
        return 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> R;
    for(int i=0;i<N-1;i++){
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }

    cout << getColumn(0,R) << " ";

    q.push({giga,0});
    visited[giga]=true;
    visited[befgiga]=true;

    while(!q.empty()){
        int v=q.front().first;
        int dis=q.front().second;
        q.pop();

        bool leaf=true;
        for(int i=0;i<adj[v].size();i++){
            int test=adj[v][i].first;
            int moreDis=adj[v][i].second;
            if(!visited[test]){
                visited[test]=true;
                leaf=false;
                q.push({test,dis+moreDis});
            }
        }

        if(leaf) ans=max(ans,dis);
    }

    cout << ans;

}
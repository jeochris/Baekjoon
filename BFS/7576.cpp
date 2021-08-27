#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, ans, dist[1003][1003];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<pair<int,int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> dist[i][j];
            if(dist[i][j]==1) q.push({j,i});
        }
    }

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>0 && ny>0 && nx<=M && ny<=N){
                if(dist[ny][nx]==0){
                    dist[ny][nx]=dist[y][x]+1;
                    q.push({nx,ny});
                }
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(dist[i][j]==0){
                cout << -1;
                return 0;
            }
            ans=max(ans,dist[i][j]-1);
        }
    }
    cout << ans;

}
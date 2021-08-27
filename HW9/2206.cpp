#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M, board[1003][1003], ans;
int dist[1003][1003][2];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<pair<pair<int,int>,int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1;i<=N;i++){
        string line;
        cin >> line;
        for(int j=0;j<M;j++) board[i][j+1]=line[j]-'0';
    }

    q.push({{1,1},0});
    dist[1][1][0]=1;
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int thru=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>0 && ny>0 && nx<=M && ny<=N){
                if(board[ny][nx]==0){
                    if(!dist[ny][nx][thru]){
                        dist[ny][nx][thru]=dist[y][x][thru]+1;
                        if(nx!=M || ny!=N) q.push({{nx,ny},thru});
                    }
                }
                else{
                    if(thru==0 && !dist[ny][nx][1]){
                        dist[ny][nx][1]=dist[y][x][0]+1;
                        q.push({{nx,ny},1});
                    }
                }
            }
        }
    }
    
    int chk1=dist[N][M][0], chk2=dist[N][M][1];
    if(chk1==0 && chk2==0) cout << -1;
    else if(chk1==0) cout << chk2;
    else if(chk2==0) cout << chk1;
    else cout << min(chk1,chk2);

}
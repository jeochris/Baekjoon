#include <iostream>
#include <queue>
using namespace std;

struct dot{
    int x;
    int y;
    int lev;
};

int board[1002][1002], ans[1002][1002];
bool visited[1002][1002];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int stX, stY;
queue<struct dot> q;

int N, M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> board[i][j];
            if(board[i][j]==2){
                stY=i;
                stX=j;
            }
        }
    }

    struct dot root;
    root.x=stX;
    root.y=stY;
    root.lev=0;

    q.push(root);
    visited[stY][stX]=true;
    while(!q.empty()){
        int cx=q.front().x;
        int cy=q.front().y;
        int clev=q.front().lev;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=cx+dx[i], ny=cy+dy[i];
            if(board[ny][nx]==0) continue;
            if(!visited[ny][nx]){
                visited[ny][nx]=true;
                ans[ny][nx]=clev+1;

                struct dot more;
                more.x=nx;
                more.y=ny;
                more.lev=clev+1;
                q.push(more);
            }
        }


    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(board[i][j]==1 && ans[i][j]==0) cout << -1 << " ";
            else cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

}
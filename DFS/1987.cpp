#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int R, C;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool spaceVisited[22][22], alphaVisited[26];
char board[22][22];

int dfs(int x,int y){
    spaceVisited[x][y]=true;
    alphaVisited[board[x][y]-'A']=true;

    int ret=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>0 && ny>0 && nx<=R && ny<=C){
            if(!spaceVisited[nx][ny] && !alphaVisited[board[nx][ny]-'A']){
                ret=max(ret,dfs(nx,ny));
            }
        }
    }

    spaceVisited[x][y]=false;
    alphaVisited[board[x][y]-'A']=false;

    return ret+1;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for(int i=1;i<=R;i++){
        string input;
        cin >> input;
        for(int j=0;j<C;j++) board[i][j+1]=input[j];
    }

    cout << dfs(1,1);

}
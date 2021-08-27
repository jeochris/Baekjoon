#include <iostream>
using namespace std;

int N, M;
int bef[32][32], aft[32][32];
int stX, stY;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int befColor, aftColor;
bool noChange=true;

void dfs(int x,int y){
    bef[y][x]=aftColor;
    for(int i=0;i<4;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(bef[ny][nx] && bef[ny][nx]==befColor){
            dfs(nx,ny);
        }
    }
}

bool same(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(bef[i][j]!=aft[i][j]) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) cin >> bef[i][j];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> aft[i][j];
            if(aft[i][j]!=bef[i][j]){
                stY=i;
                stX=j;
                noChange=false;
                befColor=bef[i][j];
                aftColor=aft[i][j];
            }
        }
    }

    if(noChange){
        cout << "YES";
        return 0;
    }

    dfs(stX,stY);
    if(same()) cout << "YES";
    else cout << "NO";

}
#include <iostream>
using namespace std;

int N, K, R;
bool road[204][204], cow[103][103], board[103][103];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans=0;

int dfs(int x,int y){
    int sum=0;
    board[y][x]=true;
    if(cow[y][x]) sum++;
    for(int k=0;k<4;k++){
        int nx=x+dx[k], ny=y+dy[k];
        if(nx>0 && ny>0 && nx<=N && ny<=N){
            if(!road[y+ny][x+nx] && !board[ny][nx]){
                sum+=dfs(nx,ny);
            }
        }
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> R;
    for(int i=0;i<R;i++){
        int y1,x1,y2,x2;
        cin >> y1 >> x1 >> y2 >> x2;
        road[y1+y2][x1+x2]=true;
    }

    for(int i=0;i<K;i++){
        int y,x;
        cin >> y >> x;
        cow[y][x]=true;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!board[i][j]){
                int tmp=dfs(j,i);
                ans+=tmp*(tmp-1)/2;
            }
        }
    }
    
    ans=K*(K-1)/2-ans;
    cout << ans;
}
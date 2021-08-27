#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T, L, dist[304][304];
int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};

int test(){
    queue<pair<int,int>> q;
    int stX, stY, edX, edY;
    memset(dist,0,sizeof(dist));

    cin >> L;
    cin >> stX >> stY >> edX >> edY;

    q.push({stX,stY});
    dist[stY][stX]=1;
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(int j=0;j<8;j++){
            int nx=x+dx[j], ny=y+dy[j];
            if(nx>=0 && ny>=0 && nx<L && ny<L){
                if(!dist[ny][nx]){
                    dist[ny][nx]=dist[y][x]+1;
                    if(ny==edY && nx==edX){
                        return dist[ny][nx]-1;
                    }
                    else q.push({nx,ny});
                }
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i=0;i<T;i++) cout << test() << "\n";

}
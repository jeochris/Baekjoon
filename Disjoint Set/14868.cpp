#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K, civi[2003][2003];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int parent[100003], height[100003];
queue<pair<int,int>> unionCheck, expandCivi;

int Find(int x){
    if(parent[x]==-1) return x;
    return parent[x]=Find(parent[x]);
}

bool Union(int x,int y){
    int u=Find(x), v=Find(y);
    if(u==v) return false;
    if(height[v]>height[u]) swap(u,v);
    parent[v]=u;
    if(height[v]==height[u]) height[u]++;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i=1;i<=K;i++){
        int x1,y1;
        cin >> x1 >> y1;
        civi[x1][y1]=i;
        parent[i]=-1;
        unionCheck.push({x1,y1});
    }

    int cnt=0, time=0;
    while(1){
        while(!unionCheck.empty()){
            auto [x,y]=unionCheck.front();
            expandCivi.push({x,y});
            unionCheck.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>0 && ny>0 && nx<=N && ny<=N){
                    if(civi[nx][ny] && civi[nx][ny]!=civi[x][y]){
                        if(Union(civi[nx][ny],civi[x][y])) cnt++;
                        if(cnt==K-1){
                            cout << time;
                            return 0;
                        }
                    }
                }
            }
        }

        time++;
        while(!expandCivi.empty()){
            auto [x,y]=expandCivi.front();
            expandCivi.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>0 && ny>0 && nx<=N && ny<=N){
                    if(civi[nx][ny]==0){
                        civi[nx][ny]=civi[x][y];
                        unionCheck.push({nx,ny});
                    }
                }
            }
        }
    }

}
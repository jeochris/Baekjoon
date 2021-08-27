#include <iostream>
#include <algorithm>
using namespace std;

int N, M, Q, H[1002][1002];
int haveMin[1002][1002], water[1002][1002], timeMin[1002][1002];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
pair<int,int> parent[1002][1002], locMin[1002][1002];

pair<int,int> Find(pair<int,int> u){
    auto [y,x]=u;
    if(parent[y][x]==u) return u;
    return parent[y][x]=Find(parent[y][x]);
}

void Union(pair<int,int> a,pair<int,int> b){
    pair<int,int> u=Find(a), v=Find(b);
    auto [y1,x1]=u;
    auto [y2,x2]=v;

    if(u==v) return;
    
    parent[y2][x2]=u;

    if(haveMin[y1][x1]>haveMin[y2][x2] || (haveMin[y1][x1]==haveMin[y2][x2] && timeMin[y1][x1]>timeMin[y2][x2])){
        haveMin[y1][x1]=haveMin[y2][x2];
        locMin[y1][x1]=locMin[y2][x2];
        timeMin[y1][x1]=timeMin[y2][x2];
    }
}

void testCase(int t){
    int y,x,cut;
    cin >> y >> x >> cut;
    H[y][x]-=cut;
    water[y][x]=1;

    auto [rootY,rootX]=Find({y,x});
    if(H[y][x]<haveMin[rootY][rootX]){
        locMin[rootY][rootX]={y,x};
        haveMin[rootY][rootX]=H[y][x];
        timeMin[rootY][rootX]=t;
    }
    for(int i=0;i<4;i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(water[ny][nx]){
            Union({ny,nx},{y,x});
        }
    }

    auto [topY,topX]=Find({y,x});
    cout << locMin[topY][topX].first << " " << locMin[topY][topX].second << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> Q;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> H[i][j];
            haveMin[i][j]=H[i][j];
            parent[i][j]={i,j};
        }
    }
    for(int i=1;i<=Q;i++){
        testCase(i);
    }

}
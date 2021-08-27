#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int parent[1003], height[1003], lier[1003], visited[1003];
vector<int> adj[1003];

int Find(int u){
    if(parent[u]==u) return u;
    return parent[u]=Find(parent[u]);
}

void change(int st){
    queue<int> q;
    memset(visited,0,sizeof(visited));

    q.push(st);
    visited[st]=1;
    lier[st]=3-lier[st];
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v]=1;
                lier[v]=3-lier[v];
                q.push(v);
            }
        }
    }
}

void Union(int u,int v){
    u=Find(u);
    v=Find(v);
    if(u==v) return;

    if(height[u]<height[v]) swap(u,v);
    parent[v]=u;

    if(height[u]==height[v]) height[u]++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=1;i<=1000;i++) parent[i]=i;

    for(int i=0;i<M;i++){
        int x,y;
        char rep;
        cin >> x >> y >> rep;

        int rootX=Find(x), rootY=Find(y);
        if(lier[x]==0 && lier[y]==0){
            if(rep=='T'){
                lier[x]=1; lier[y]=1;
            }
            else{
                lier[x]=1; lier[y]=2;
            }
        }
        else if(lier[x]==0){
            if(rep=='T') lier[x]=lier[y];
            else lier[x]=3-lier[y];
        }
        else if(lier[y]==0){
            if(rep=='T') lier[y]=lier[x];
            else lier[y]=3-lier[x];
        }

        if(rootX==rootY){
            if(rep=='T' && lier[x]!=lier[y]){
                cout << i;
                return 0;
            }
            else if(rep=='L' && lier[x]==lier[y]){
                cout << i;
                return 0;
            }
        }
        else{
            int tmp;
            if(height[rootX]>height[rootY]) tmp=rootY;
            else tmp=rootX;

            if(rep=='T' && lier[x]!=lier[y]) change(tmp);
            else if(rep=='L' && lier[x]==lier[y]) change(tmp);
        }

        adj[x].push_back(y);
        adj[y].push_back(x);
        Union(x,y);
        
    }
    cout << M;

}
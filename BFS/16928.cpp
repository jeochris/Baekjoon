#include <iostream>
#include <queue>
using namespace std;

int N, M, jump[102];
int dist[102];
queue<int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<N+M;i++){
        int a,b;
        cin >> a >> b;
        jump[a]=b;
    }

    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=1;i<=6;i++){
            int nx=u+i;
            if(nx>1 && nx<=100 && dist[nx]==0){
                dist[nx]=dist[u]+1;
                if(nx==100){
                    cout << dist[nx];
                    return 0;
                }
                if(jump[nx] && dist[jump[nx]]==0){
                    dist[jump[nx]]=dist[nx];
                    q.push(jump[nx]);
                }
                else if(jump[nx]==0) q.push(nx);
            }
        }
    }

}
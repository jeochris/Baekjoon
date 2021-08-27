#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, pop[12], adj[12][12], eachConnect, ans=2000;
int testCase[12];

bool checkTeam(int which,int tot){
    if(tot==1) return true;

    int root, sum=0, visited[12]={0,};
    for(int i=1;i<=N;i++)if(testCase[i]==which){
        root=i;
        sum++;
        break;
    }

    queue<int> q;
    q.push(root);
    visited[root]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=1;v<=N;v++){
            if(visited[v]==0 && adj[u][v] && testCase[v]==which){
                visited[v]=1;
                sum++;
                q.push(v);
            }
        }
    }

    if(sum==tot) return true;
    else return false;
    
}

int diff(){
    int sum1=0, sum0=0;
    for(int i=1;i<=N;i++){
        if(testCase[i]) sum1+=pop[i];
        else sum0+=pop[i];
    }
    return abs(sum1-sum0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1;i<=N;i++) cin >> pop[i];
    for(int i=1;i<=N;i++){
        cin >> eachConnect;
        for(int j=0;j<eachConnect;j++){
            int tmp;
            cin >> tmp;
            adj[i][tmp]=1;
        }
    }

    int lastCase=pow(2,N-1);
    testCase[1]=0; // 1번노드는 0팀 고정

    for(int i=1;i<lastCase;i++){
        int bin=i, st=2, team1=0;
        while(bin){
            testCase[st]=bin%2;
            team1+=testCase[st];
            bin/=2;
            st++;
        }
        int team0=N-team1;
        if(checkTeam(0,team0) && checkTeam(1,team1)) ans=min(ans,diff());
    }

    if(ans==2000) cout << -1;
    else cout << ans;

}
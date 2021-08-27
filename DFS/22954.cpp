#include <iostream>
#include <vector>
using namespace std;

int N, M, leaf;
vector<pair<int,int>> adjDFS[100003];
bool visited[100003];

int countDFS(int x){
    int cnt=0;
    bool haveChild=false;
    visited[x]=true;
    cnt++;
    for(auto [v,c]:adjDFS[x]){
        if(!visited[v]){
            haveChild=true;
            cnt+=countDFS(v);
        }
    }
    if(!haveChild) leaf=x;
    return cnt;
}

void printDFS(int x,int which){
    visited[x]=true;
    if(which==3) cout << x << " ";
    for(auto [v,c]:adjDFS[x]){
        if(which==1){
            if(!visited[v]){
                cout << c << " ";
                printDFS(v,which);
            }
        }
        else if(which==2){
            if(!visited[v] && v!=leaf){
                cout << c << " ";
                printDFS(v,which);
            }
        }
        else{
            if(!visited[v]){
                printDFS(v,which);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=1;i<=M;i++){
        int a,b;
        cin >> a >> b;
        adjDFS[a].push_back({b,i});
        adjDFS[b].push_back({a,i});
    }

    // 제외 - 정점 2개 이하
    if(N<=2){
        cout << -1;
        return 0;
    }

    int conGraph=0;
    pair<int,int> cnt[2];
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            // 제외 - 연결 그래프 3개 이상
            if(conGraph==2){
                cout << -1;
                return 0;
            }
            cnt[conGraph]={countDFS(i),i};
            conGraph++;
        }
    }

    // 제외 - 연결 그래프 2개 & 사이즈 같음
    if(conGraph==2 && cnt[0].first==cnt[1].first){
        cout << -1;
        return 0;
    }

    fill(visited+1,visited+N+1,false);

    if(conGraph==1){
        cout << N-1 << " " << 1 << "\n";
        for(int i=1;i<=N;i++)if(i!=leaf) cout << i << " ";
        cout << "\n";
        printDFS(cnt[0].second,2);
        cout << "\n" << leaf;
    }
    else{
        cout << cnt[0].first << " " << cnt[1].first << "\n";
        printDFS(cnt[0].second,3);
        cout << "\n";
        fill(visited+1,visited+N+1,false);
        printDFS(cnt[0].second,1);
        cout << "\n";
        fill(visited+1,visited+N+1,false);
        printDFS(cnt[1].second,3);
        cout << "\n";
        fill(visited+1,visited+N+1,false);
        printDFS(cnt[1].second,1);
    }

}
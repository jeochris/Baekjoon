#include <iostream>
#include <deque>
using namespace std;

int N, K;
bool visited[100002];
deque<pair<int,int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    q.push_back({N,0});
    visited[N]=true;

    while(!q.empty()){
        int loc=q.front().first;
        int lev=q.front().second;
        q.pop_front();

        if(loc==K){
            cout << lev;
            return 0;
        }

        if(loc-1>=0 && loc-1<=1e5 && !visited[loc-1]){
            visited[loc-1]=true;
            q.push_back({loc-1,lev+1});
        }
        if(loc+1>=0 && loc+1<=1e5 && !visited[loc+1]){
            visited[loc+1]=true;
            q.push_back({loc+1,lev+1});
        }
        if(loc*2>=0 && loc*2<=1e5 && !visited[loc*2]){
            visited[loc*2]=true;
            q.push_back({loc*2,lev+1});
        }
    }

}
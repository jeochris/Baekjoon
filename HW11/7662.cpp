#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int visited[1000004];

void testCase(){
    int K;
    long long int n;
    char op;
    cin >> K;

    priority_queue<pair<long long int,int>> maxHeap, minHeap;
    memset(visited,0,sizeof(visited));

    for(int i=0;i<K;i++){
        cin >> op >> n;
        if(op=='I'){
            maxHeap.push({n,i});
            minHeap.push({-n,i});
            visited[i]=1;
        }
        else{
            if(n==1){
                while(!maxHeap.empty() && !visited[maxHeap.top().second]) maxHeap.pop();
                if(!maxHeap.empty()){
                    visited[maxHeap.top().second]=0;
                    maxHeap.pop();
                }
            }
            else{
                while(!minHeap.empty() && !visited[minHeap.top().second]) minHeap.pop();
                if(!minHeap.empty()){
                    visited[minHeap.top().second]=0;
                    minHeap.pop();
                }
            }
        }
    }

    while(!maxHeap.empty() && !visited[maxHeap.top().second]) maxHeap.pop();
    while(!minHeap.empty() && !visited[minHeap.top().second]) minHeap.pop();

    if(!maxHeap.empty() && !minHeap.empty()){
        cout << maxHeap.top().first << " " << -minHeap.top().first << "\n";
    }
    else cout << "EMPTY" << "\n";


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        testCase();
    }
}
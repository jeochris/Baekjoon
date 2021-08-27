#include <iostream>
#include <queue>
using namespace std;

int N, ans=0;
priority_queue<int> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1;i<=N*N;i++){
        int a;
        cin >> a;
        if(i<=N) pq.push(-a);
        else{
            if(pq.top()>-a){
                pq.pop();
                pq.push(-a);
            }
        }
        
    }

    cout << -pq.top();

}
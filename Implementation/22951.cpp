#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<pair<int,int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i=1;i<=N;i++){
        for(int j=0;j<K;j++){
            int a;
            cin >> a;
            q.push({a,i});
        }
    }

    while(q.size()>1){
        int found=q.front().first;
        q.pop();

        found=found%q.size();
        if(found==0) found+=q.size();
        found--;

        while(found--){
            q.push(q.front());
            q.pop();
        }
    }

    cout << q.front().second << " " << q.front().first;

}
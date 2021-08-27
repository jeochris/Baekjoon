#include <iostream>
using namespace std;

int N, S, arr[21], ans=0;

void add(int idx,int cur){
    cur+=arr[idx];
    if(cur==S) ans++;
    for(int i=idx+1;i<N;i++) add(i,cur);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> arr[i];

    for(int i=0;i<N;i++) add(i,0);
    cout << ans;

}
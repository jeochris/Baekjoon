#include <iostream>
#include <algorithm>
using namespace std;

int N, line[503], dp[503], ans;

int getDP(int x){
    int& ret=dp[x];
    if(dp[x]!=0) return ret;

    int high=0;
    for(int i=500;i>x;i--){
        if(line[i]>line[x]){
            high=max(high,getDP(i));
        }
    }
    ret=high+1;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        line[a]=b;
    }

    // dp[i] := i번째 전깃줄 시작으로 교점 없이 이룰 수 있는 최대 개수

    for(int i=500;i>0;i--)if(line[i]!=0){
        ans=max(ans,getDP(i));
    }

    cout << N-ans;
}
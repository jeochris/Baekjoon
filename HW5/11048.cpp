#include <iostream>
#include <algorithm>
using namespace std;

int N, M, candy[1005][1005];
int dp[1005][1005]={-1,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) cin >> candy[i][j];
    }

    dp[1][1]=candy[1][1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+candy[i+1][j]);
            dp[i][j+1]=max(dp[i][j+1],dp[i][j]+candy[i][j+1]);
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+candy[i+1][j+1]);
        }
    }
    cout << dp[N][M];

}
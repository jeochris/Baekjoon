#include <iostream>
#include <algorithm>
using namespace std;

int N, ans=-1;
int tri[503][503], dp[503][503]={-1,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++) cin >> tri[i][j];
    }

    dp[1][1]=tri[1][1];
    for(int i=1;i<N;i++){
        for(int j=1;j<=i;j++){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+tri[i+1][j]);
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+tri[i+1][j+1]);
        }
    }

    for(int i=1;i<=N;i++) ans=max(ans,dp[N][i]);
    cout << ans;

}
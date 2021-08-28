#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N, sameCase=0, divi=1e9+7;
long long int M, dp[302][7502];
string line;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> line;
    for(int i=0;i<N;i++){
        sameCase+=('z'-line[i]);
    }
    if(M>sameCase) M=sameCase;

    for(int i=1;i<=N;i++){
        for(int j=0;j<=M;j++){
            if(j==0) dp[i][j]=1;
            else if(i==1) dp[i][j]=1;
            else dp[i][j]=dp[i][j-1]+dp[i-1][j];
            dp[i][j]%=divi;
        }
    }

    cout << dp[N][M];

}
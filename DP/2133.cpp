#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int lastTwo[32], lastOne[32], dp[32];

    cin >> N;

    dp[0]=1;
    dp[1]=0;
    lastTwo[1]=1;
    lastOne[1]=0;

    for(int i=2;i<=N;i++){
        lastTwo[i]=dp[i-1]+lastOne[i-1];
        lastOne[i]=lastTwo[i-1];
        dp[i]=lastOne[i]+dp[i-2]+lastTwo[i-1];
    }

    cout << dp[N];

}
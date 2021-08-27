#include <iostream>
using namespace std;

int T, dp[15];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    for(int i=1;i<11;i++){
        dp[i+1]+=dp[i];
        dp[i+2]+=dp[i];
        dp[i+3]+=dp[i];
    }

    cin >> T;
    
    for(int i=0;i<T;i++){
        int tmp;
        cin >> tmp;
        cout << dp[tmp] << "\n";
    }

}
#include <iostream>
#include <algorithm>
using namespace std;

int N, card[1004], ans, dp[1004];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1;i<=N;i++) cin >> card[i];

    dp[1]=1;
    for(int i=2;i<=N;i++){
        int tmp=0;
        for(int j=1;j<i;j++)if(card[j]<card[i]){
            tmp=max(tmp,dp[j]);
        }
        tmp++;
        dp[i]=tmp;
    }

    for(int i=1;i<=N;i++) ans=max(ans,dp[i]);
    cout << ans;

}
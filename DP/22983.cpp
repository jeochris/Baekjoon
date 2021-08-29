#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
char arr[3004][3004];
long long int ans=0, dp[3004][3004];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1;i<=N;i++){
        string line;
        cin >> line;
        for(int j=1;j<=M;j++) arr[j][i]=line[j-1];
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(arr[j-1][i-1]==arr[j][i] && arr[j-1][i]!=arr[j][i] && arr[j][i-1]!=arr[j][i]){
                dp[j][i]=min(dp[j-1][i-1],min(dp[j-1][i],dp[j][i-1]));
            }
            dp[j][i]++;
            ans+=dp[j][i];
        }
    }
    cout << ans;

}
#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[1003][1003];

int checkPrime(int x,int y){
    if(y%2==0) return 0;

    int tmp=y, lev=0, chk=y;
    while(tmp!=0){
        tmp/=10;
        lev++;
    }
    while(lev--) x*=10;
    chk+=x;

    if(chk%3==0) return 0;
    
    for(int i=5;i*i<=chk;i++) if(chk%i==0) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    dp[1][1]=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i!=1 || j!=1) dp[i][j]=max(dp[i-1][j],dp[i][j-1])+checkPrime(i,j);
        }
    }

    cout << dp[N][N];

}
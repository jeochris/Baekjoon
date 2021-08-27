#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

string A,B;
int dp[4002][4002], ans;

int getDP(int x,int y){
    if(x<0 || y<0) return 0;

    int& ret=dp[x][y];
    if(ret!=-1) return ret;

    if(A[x]!=B[y]) ret=0;
    else ret=getDP(x-1,y-1)+1;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    memset(dp,-1,sizeof(dp));
    for(int i=0;i<A.length();i++){
        for(int j=0;j<B.length();j++){
            ans=max(ans,getDP(i,j));
        }
    }

    cout << ans;

}
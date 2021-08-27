#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, emptyDay[102];
int dp[105][105];

int getDP(int st,int coup){
    if(st>=N+1) return 0;

    int& ret=dp[st][coup];
    if(ret!=-1) return ret;

    ret=1e9;
    if(emptyDay[st]) ret=getDP(st+1,coup);
    else{
        ret=min(ret,getDP(st+1,coup)+10000);
        ret=min(ret,getDP(st+3,coup+1)+25000);
        ret=min(ret,getDP(st+5,coup+2)+37000);
        if(coup>=3) ret=min(ret,getDP(st+1,coup-3));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<M;i++){
        int tmp;
        cin >> tmp;
        emptyDay[tmp]=1;
    }

    memset(dp,-1,sizeof(dp));

    // dp[i][j] := i일부터 채우고자 하는데 j개 쿠폰 가지고 있음

    cout << getDP(1,0);

}
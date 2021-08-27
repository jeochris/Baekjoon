#include <iostream>
#include <algorithm>
using namespace std;

int N, K, C, A[12], give[12], chk[12];
long long int ans=1e18;

bool check(long long int T){
    long long int sum=0;
    for(int i=1;i<=N;i++){
        sum+=(T/chk[i]);
        if(sum>=K) return true;
    }
    return false;
}

void updateAns(){
    long long int s=1, e=1e18, cur=1e18;
    while(s<=e){
        long long int mid=(s+e)/2;
        if(check(mid)){
            cur=min(cur,mid);
            e=mid-1;
        }
        else s=mid+1;
    }
    ans=min(ans,cur);
}

void makeGive(int st,int left){
    if(st>N && left!=0) return;
    if(left==0){
        for(int i=1;i<=N;i++){
            chk[i]=A[i]-give[i];
        }
        updateAns();
        return;
    }

    int have=left;
    while(left>=0){
        if(left<A[st]){
            give[st]=left;
            makeGive(st+1,have-left);
        }
        left--;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int avC=0;
    cin >> N >> K >> C;
    for(int i=1;i<=N;i++){
        cin >> A[i];
        avC+=(A[i]-1);
    }
    if(avC<C) C=avC;

    makeGive(1,C);
    cout << ans;

}
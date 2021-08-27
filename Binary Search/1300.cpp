#include <iostream>
#include <algorithm>
using namespace std;

long long int N, K;
long long int ans=1e10;

bool check(long long int num){
    long long int cnt=0;
    for(long long int i=1;i<=N;i++){
        cnt+=min(N,num/i);
    }
    if(cnt>=K) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    long long int s=1;
    long long int e=1e10;
    while(s<=e){
        long long int mid=(s+e)/2;
        if(check(mid)){
            ans=min(ans,mid);
            e=mid-1;
        }
        else s=mid+1;
    }

    cout << ans;

}
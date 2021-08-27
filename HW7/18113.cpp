#include <iostream>
#include <vector>
using namespace std;

int N, K, M, ans;
vector<int> kimbap;

bool check(int div){
    int part=0;

    for(int i=0;i<kimbap.size();i++){
        part+=(kimbap[i]/div);
    }

    if(part>=M) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> M;
    for(int i=0;i<N;i++){
        int len;
        cin >> len;
        if(len<=K) continue;
        else if(len>=2*K) kimbap.push_back(len-2*K);
        else kimbap.push_back(len-K);
    }

    int s=1, e=1e9;
    while(s<=e){
        int mid=(s+e)/2;
        if(check(mid)){
            ans=max(ans,mid);
            s=mid+1;
        }
        else e=mid-1;
    }

    if(!ans) cout << -1;
    else cout << ans;

}
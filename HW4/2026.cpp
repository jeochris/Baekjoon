#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int K, N, F, ans=0;
int arr[905][905];
vector<pair<int,int>> fr;

void check(vector<int> cur){
    if(cur.size()==K){
        ans=1;
        for(int i=0;i<cur.size();i++) cout << cur[i] << "\n";
        return;
    }
    for(int i=cur.back()+1;i<=N-K+cur.size()+1;i++){
        bool chk=true;
        for(int j=0;j<cur.size();j++){
            if(arr[cur[j]][i]==0){
                chk=false;
                break;
            }
        }
        if(chk){
            cur.push_back(i);
            check(cur);
        }
        if(ans) return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N >> F;

    for(int i=0;i<F;i++){
        int a,b;
        cin >> a >> b;
        if(a>b) swap(a,b);
        fr.push_back({a,b});

        arr[a][b]=1;
        arr[b][a]=1;
    }
    sort(fr.begin(),fr.end());

    for(int i=0;i<F;i++)if(ans==0){
        vector<int> make_k;
        make_k.push_back(fr[i].first);
        make_k.push_back(fr[i].second);
        check(make_k);
        if(ans) break;
    }
    if(ans==0) cout << -1;

}
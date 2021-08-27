#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
long long int ans=1e18;
vector<long long int> tk;

bool check(long long int time){
    long long int people=0;
    for(int i=0;i<tk.size();i++){
        people+=(time/tk[i]);
        if(people>=M) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        long long int tmp;
        cin >> tmp;
        tk.push_back(tmp);
    }

    long long int s=1;
    long long int e=1e18;
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
#include <iostream>
#include <algorithm>
using namespace std;

int T;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i=0;i<T;i++){
        long long int N, K;
        cin >> N >> K;
        if(K>=N) K=N-1;

        long long int ans=N*(K+1);
        ans-=K*(K+1)/2;
        ans*=4;
        cout << ans << "\n";
    }

}
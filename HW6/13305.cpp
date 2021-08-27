#include <iostream>
#include <algorithm>
using namespace std;

long long int ans, cur=2e9, road[100004];
int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N-1;i++){
        cin >> road[i];
    }
    for(int i=0;i<N-1;i++){
        long long int price;
        cin >> price;
        cur=min(cur,price);
        ans+=road[i]*cur;
    }
    cin >> cur;

    cout << ans;

}
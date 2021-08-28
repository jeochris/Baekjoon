#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long int K, getMax=0;
vector<long long int> sp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        sp.push_back(tmp);
    }

    sort(sp.begin(),sp.end());

    for(int i=1;i<N;i++){
        long long int tmp=0;
        tmp+=sp[0]*i;
        tmp+=sp[i]*(N-i);
        getMax=max(tmp,getMax);
    }

    if(K%getMax==0) cout << K/getMax;
    else cout << K/getMax+1;
}
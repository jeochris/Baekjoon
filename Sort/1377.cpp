#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int,int>> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tmp;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        v.push_back({tmp,i});
    }

    sort(v.begin(),v.end());

    int turn=0;
    for(int i=0;i<N;i++) turn=max(v[i].second-i,turn);
    
    cout << turn+1;

}
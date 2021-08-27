#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int N;
vector<pair<int,int>> road, parent;

bool comp(pair<int,int> x,pair<int,int> y){
    return x.first>y.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int sum=0;

    cin >> N;
    for(int i=1;i<=N;i++){
        int input;
        cin >> input;
        sum+=input;
        road.push_back({input,i});
    }

    if(sum%2==1 || N!=(sum/2)+1){
        cout << "BRAK";
        return 0;
    }

    sort(road.begin(),road.end(),comp);

    parent.push_back(road[0]);
    int idx=1;

    for(int i=0;i<N;i++){
        if(i) parent[i].first--;
        while(parent[i].first--){
            parent.push_back(road[idx]);
            cout << parent[i].second << " " << road[idx].second << "\n";
            idx++;
        }
    }
}
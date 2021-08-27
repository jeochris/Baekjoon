#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, k;
vector<int> chicken;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tmp;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        chicken.push_back(tmp);
    }
    cin >> k;

    int part=N/k;
    for(int i=0;i<k;i++){
        sort(chicken.begin()+i*part,chicken.begin()+(i+1)*part);
    }

    for(int i=0;i<N;i++){
        cout << chicken[i] << " ";
    }

}
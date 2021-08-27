#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    vector<int> circle;

    cin >> N >> K;

    for(int i=0;i<N;i++) circle.push_back(i+1);

    cout << "<";

    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++) circle.push_back(circle[i*K+j]);
        cout << circle.back();
        circle.pop_back();
        if(i!=N-1) cout << ", ";
    }
    
    cout << ">";
}
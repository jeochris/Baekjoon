#include <iostream>
#include <string>
#include <deque>
using namespace std;

int N,K;
long long int fr=0;
string name;
deque<int> dq[21];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> name;
        int len=name.length();
        while(!dq[len].empty() && i-dq[len].front()>K) dq[len].pop_front();
        fr+=dq[len].size();
        dq[len].push_back(i);
    }

    cout << fr;

}
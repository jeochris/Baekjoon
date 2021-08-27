#include <iostream>
#include <string>
#include <deque>
using namespace std;

int N, K, M;
deque<int> dq;

void rightway(){
    for(int i=0;i<K-1;i++){
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout << dq.front() << "\n";
    dq.pop_front();
}

void leftway(){
    for(int i=0;i<K-1;i++){
        dq.push_front(dq.back());
        dq.pop_back();
    }
    cout << dq.back() << "\n";
    dq.pop_back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> M;
    for(int i=0;i<N;i++) dq.push_back(i+1);

    int cnt=0;
    while(!dq.empty()){
        if((cnt/M)%2==0) rightway();
        else leftway();
        cnt++;
    }

}
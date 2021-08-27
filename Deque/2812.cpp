#include <iostream>
#include <string>
#include <deque>
using namespace std;

int N, K;
string num;
deque<int> line;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> num;

    line.push_back(10);

    int step=0;
    for(int i=0;i<N;i++){
        int tmp=num[i]-'0';
        while(step<K && line.back()<tmp){
            line.pop_back();
            step++;
        }
        line.push_back(tmp);
    }

    line.pop_front();
    while(step<K){
        line.pop_back();
        step++;
    }

    while(!line.empty()){
        cout << line.front();
        line.pop_front();
    }

}
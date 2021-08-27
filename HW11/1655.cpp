#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> L;
priority_queue<int,vector<int>,greater<int>> R;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while(N--){
        int input, fromL, fromR;
        cin >> input;

        if(L.empty()) L.push(input);
        else if(R.empty()){
            if(input>=L.top()) R.push(input);
            else{
                R.push(L.top());
                L.pop();
                L.push(input);
            }
        }

        else{
            fromL=L.top();
            fromR=R.top();

            if(L.size()==R.size()){
                if(input>=fromR){
                    L.push(fromR);
                    R.pop();
                    R.push(input);
                }
                else L.push(input);
            }
            else{
                if(input<=fromL){
                    R.push(fromL);
                    L.pop();
                    L.push(input);
                }
                else R.push(input);
            }
        } 

        cout << L.top() << "\n";

    }


}
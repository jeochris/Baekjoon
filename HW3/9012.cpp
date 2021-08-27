#include <iostream>
#include <string>
#include <deque>
using namespace std;

int VPS(string line){
    deque<char> dq;
    for(int i=0;i<line.length();i++){
        if(line[i]=='(') dq.push_back('(');
        else{
            if(dq.empty()) return 0;
            if(dq.back()!='(') return 0;
            dq.pop_back();
        }
    }
    if(dq.empty()) return 1;
    else return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string line;

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> line;
        if(VPS(line)) cout << "YES\n";
        else cout << "NO\n";
    }

}
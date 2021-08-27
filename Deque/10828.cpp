#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
string line;
stack<int> st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> line;
        if(line[1]=='u'){
            int tmp;
            cin >> tmp;
            st.push(tmp);
        }

        else if(line[0]=='p'){
            if(st.empty()) cout << -1 << "\n";
            else{
                cout << st.top() << "\n";
                st.pop();
            }
        }

        else if(line[0]=='s') cout << st.size() << "\n";
        else if(line[0]=='e'){
            if(st.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else{
            if(st.empty()) cout << -1 << "\n";
            else cout << st.top() << "\n";
        }
    }
}


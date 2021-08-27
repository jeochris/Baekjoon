#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, tmp;
vector<int> tech;
deque<int> last;
deque<deque<int>> line;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        tech.push_back(tmp);
    }

    line.push_back(last);

    for(int i=0;i<N;i++){
        tmp=tech.back();
        if(tmp==1){
            deque<int> v;
            v.push_front(i+1);
            line.push_front(v);
        }
        else if(tmp==2) line.front().push_back(i+1);
        else line.back().push_back(i+1);
        tech.pop_back();
    }

    while(!line.empty()){
        if(line.size()>1){
            // cout 1s
            cout << line.front().front() << " ";
            line.front().pop_front();
            // cout 2s of 1
            while(!line.front().empty()){
                cout << line.front().back() << " ";
                line.front().pop_back();
            }
            line.pop_front();
        }
        else{
            while(!line.back().empty()){
                cout << line.back().front() << " ";
                line.back().pop_front();
            }
            line.pop_back();
        }
    }
    
}
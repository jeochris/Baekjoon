#include <iostream>
#include <vector>
using namespace std;

int N, tmp, idx;
vector<pair<int,int>> ball;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        ball.push_back({tmp,i+1}); 
    }

    idx=0;

    for(int i=0;i<N;i++){
        int next=ball[idx].first;
        cout << ball[idx].second << " ";
        ball.erase(ball.begin()+idx);

        if(ball.size()==0) break;
        int size=ball.size();

        if(next>0) idx=(idx-1+next)%size;
        else idx=(idx+next)%size;
        if(idx<0) idx=idx+size;
    }
}
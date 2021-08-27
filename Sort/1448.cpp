#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> straw;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        straw.push_back(tmp);
    }

    sort(straw.begin(),straw.end(),cmp);
    for(int i=0;i<N-2;i++){
        if(straw[i]<straw[i+1]+straw[i+2]){
            cout << straw[i]+straw[i+1]+straw[i+2];
            return 0;
        }
    }
    cout << -1;

}
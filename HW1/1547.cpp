#include <iostream>
#include <algorithm>
using namespace std;

int M, X, Y;
int ball[3]={1,0,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    for(int i=0;i<M;i++){
        cin >> X >> Y;
        swap(ball[X-1],ball[Y-1]);
    }
    for(int i=0;i<3;i++)if(ball[i]==1) cout << i+1;
}
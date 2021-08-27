#include <iostream>
#include <algorithm>
using namespace std;

int N;
int weight[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++) cin >> weight[i];
    sort(weight,weight+N);

    int max=0;
    for(int i=0;i<N;i++){
        if(weight[i]>max+1) break;
        max+=weight[i];
    }
    cout << max+1;

}
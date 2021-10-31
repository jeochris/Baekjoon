#include <iostream>
using namespace std;

int N, have[1000003];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int ans=N, tmp;
    for(int i=0;i<N;i++){
        cin >> tmp;
        have[tmp]++;
    }
    for(int i=0;i<N;i++){
        cin >> tmp;
        if(have[tmp]>0){
            have[tmp]--;
            ans--;
        }
    }
    cout << ans;

}
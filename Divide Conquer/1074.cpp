#include <iostream>
#include <cmath>
using namespace std;

int N, r, c, ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;
    int div=pow(2,N-1);

    while(div){
        int rpart=r/div;
        int cpart=c/div;
        ans+=(rpart*2+cpart)*div*div;
        r%=div;
        c%=div;
        div/=2;
    }

    cout << ans;

}
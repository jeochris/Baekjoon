#include <iostream>
#include <vector>
using namespace std;

int T, N, M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i=0;i<T;i++){
        cin >> N >> M;
        for(int j=0;j<M;j++){
            int a,b;
            cin >> a >> b;
        }
        cout << N-1 << "\n";
    }

}
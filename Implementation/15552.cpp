#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, a, b;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> a >> b;
        cout << a+b << "\n";
    }
}
#include <iostream>
#include <string>
using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int st, ed;
    cout << '?' << " " << N << "\n";
    std::cout << std::flush;
    cin >> ed;

    cout << '?' << " " << 1 << "\n";
    std::cout << std::flush;
    cin >> st;

    cout << '!' << " ";
    if(st==ed) cout << 0;
    else if(st==1) cout << -1;
    else cout << 1;
    std::cout << std::flush;
}
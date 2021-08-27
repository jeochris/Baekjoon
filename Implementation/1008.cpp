#include <iostream>
using namespace std;

double A,B;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    cout << fixed;
    cout.precision(10);
    cout << A/B;
}
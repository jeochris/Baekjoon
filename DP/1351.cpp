#include <iostream>
#include <map>
using namespace std;

long long N, P, Q;
map<long long int,long long int> A;

long long int findA(long long int n){
    if(n==0) return 1;
    if(A.find(n)!=A.end()) return A[n];

    long long int tmp=findA(n/P)+findA(n/Q);
    A[n]=tmp;
    return tmp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> P >> Q;
    cout << findA(N);
}
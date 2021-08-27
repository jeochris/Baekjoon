#include <iostream>
#include <string>
using namespace std;

int N, K, arr[1000003];
string num;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> num;
    for(int i=N-1;i>=0;i--) arr[i]=num[N-1-i]-'0';
    cin >> K;

    for(int i=K-1;i>=0;i--){
        if(arr[i]==1){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

}
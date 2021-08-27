#include <iostream>
using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    if(N%2==0){
        for(int i=1;i<N/2;i++){
            cout << i << " " << N-i << " ";
        }
        cout << N/2 << " " << N;
    }
    else{
        for(int i=1;i<=N/2;i++){
            cout << i << " " << N-i << " ";
        }
        cout << N;
    }
    

}
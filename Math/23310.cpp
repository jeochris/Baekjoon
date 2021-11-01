#include <iostream>
#include <algorithm>
using namespace std;

int N, M, cycle;
int X[20003], inCycle[20003];

int gcd(int a, int b){
    int r;
    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> X[i];

    cycle=N/gcd(N,M)*M;

    for(int i=1;i<=cycle;i++){
        if(i%M!=0) inCycle[i%N]++;
    }
    inCycle[N]=inCycle[0];

    int minCycle=2e8;
    for(int i=1;i<=N;i++){
        if(inCycle[i]!=0){
            if(X[i]%inCycle[i]==0) minCycle=min(minCycle,X[i]/inCycle[i]);
            else minCycle=min(minCycle,X[i]/inCycle[i]+1);
        }
    }

    minCycle--;
    for(int i=1;i<=N;i++) X[i]-=(minCycle*inCycle[i]);

    for(int i=1;i<=cycle;i++){
        if(i%M!=0){
            if(i%N==0){
                X[N]--;
                if(X[N]==0){
                    cout << N;
                    return 0;
                }
            }
            else{
                X[i%N]--;
                if(X[i%N]==0){
                    cout << i%N;
                    return 0;
                }
            }
        }
    }

}
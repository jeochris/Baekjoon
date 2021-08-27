#include <iostream>
#include <cmath>
using namespace std;

int s, N, K;
long long int R1, R2, C1, C2;

int output(int time,long long int x,long long int y){
    if(time==0) return 0;

    long long int cur=pow(N,time-1);
    long long int rpart=x/cur, cpart=y/cur;
    
    if(rpart>=(N-K)/2 && rpart<=(N+K-2)/2 && cpart>=(N-K)/2 && cpart<=(N+K-2)/2) return 1;
    else return output(time-1,x-rpart*cur,y-cpart*cur);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

    for(long long int i=R1;i<=R2;i++){
        for(long long int j=C1;j<=C2;j++){
            cout << output(s,i,j);
        }
        cout << "\n";
    }

}
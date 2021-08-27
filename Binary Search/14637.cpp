#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;
long long int ans=-1e9, mul=1e6, sect=-1001;
vector<long long int> d, s;
double realAns;

bool check(long long int x){
    double sum=0;
    for(int i=0;i<N;i++){
        sum+=d[i]/(double)(s[i]+x);
    }
    if(sum>=T) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> T;
    for(int i=0;i<N;i++){
        long long int a,b;
        cin >> a >> b;
        d.push_back(a*mul);
        s.push_back(b*mul);
        sect=max(sect,-b);
    }

    long long int s=sect*mul+1;
    long long int e=1e9*mul;
    while(s<=e){
        long long int mid=(s+e)/2;
        if(check(mid)){
            ans=max(ans,mid);
            s=mid+1;
        }
        else e=mid-1;
    }

    realAns=ans/(double)mul;
    cout << fixed;
    cout.precision(6);
    cout << realAns;

}
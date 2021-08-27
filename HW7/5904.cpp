#include <iostream>
#include <vector>
using namespace std;

int N;
char ans;
vector<long long int> s;

void makeS(int lev){
    long long int putIn;
    if(lev==0) putIn=3;
    else putIn=s.back()*2+(lev+3);
    s.push_back(putIn);

    if(N<=putIn) return;
    else makeS(lev+1);
}

void find(int lev,int x){
    if(lev==0){
        if(x==1) ans='m';
        else ans='o';
        return;
    }

    if(x<=s[lev-1]) find(lev-1,x);
    else if(x>s[lev-1]+lev+3) find(lev-1,x-s[lev-1]-lev-3);
    else{
        x-=s[lev-1];
        if(x==1) ans='m';
        else ans='o';
        return;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    makeS(0);
    find(s.size()-1,N);
    cout << ans;

}
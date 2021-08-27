#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;

struct program{
    int hi;
    int di;
    int late;
};

bool comp(program x,program y){
    bool ret=false;
    if(x.di<y.di) ret=true;
    else if(x.di==y.di && x.hi<y.hi) ret=true;
    return ret;
}

void testCase(){
    int N, tmp, ans=2e9;
    cin >> N;

    vector<program> v(N);
    for(int i=0;i<N;i++){
        cin >> tmp;
        v[i].hi=tmp;
    }
    for(int i=0;i<N;i++){
        cin >> tmp;
        v[i].di=tmp;
    }

    sort(v.begin(),v.end(),comp);

    int curTime=0;
    vector<int> maxUntil;
    for(int i=0;i<N;i++){
        curTime+=v[i].hi;
        v[i].late=max(0,curTime-v[i].di);
        if(i==0) maxUntil.push_back(v[i].late);
        else maxUntil.push_back(max(maxUntil[i-1],v[i].late));
    }

    int curMax=0;
    for(int i=N-1;i>=0;i--){
        curMax=max(curMax,v[i].late);
        tmp=max(0,curMax-(v[i].hi-1));
        if(i) tmp=max(maxUntil[i-1],tmp);
        ans=min(ans,tmp);
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i=0;i<T;i++) testCase();
}
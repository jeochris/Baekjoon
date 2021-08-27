#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct bus{
    int st;
    int ed;
    int idx;
};

bool comp(bus x,bus y){
    bool ret=false;
    if(x.st<y.st) ret=true;
    else if(x.st==y.st && x.ed>y.ed) ret=true;
    return ret;
}

int M, N;
vector<bus> v;
vector<int> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1;i<=M;i++){
        int a,b;
        cin >> a >> b;

        struct bus tmp;
        tmp.idx=i;
        tmp.ed=b;
        tmp.st=a;
        if(a>b){
            tmp.st-=N;
            v.push_back(tmp);
            tmp.st+=N;
            tmp.ed+=N;
            v.push_back(tmp);
        }
        else v.push_back(tmp);
    }

    sort(v.begin(),v.end(),comp);

    int currentEnd=0;
    for(int i=0;i<v.size();i++){
        if(v[i].ed>currentEnd){
            currentEnd=v[i].ed;
            if(v[i].st>=0) ans.push_back(v[i].idx);
        }
    }

    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";

}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct fire{
    double div;
    int ai;
    int bi;
};

bool comp(fire x,fire y){
    return x.div<y.div;
}

int n, ans, zeroA;
vector<struct fire> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a==0){
            zeroA+=b;
            zeroA%=40000;
        }
        else{
            struct fire tmp;
            tmp.div=b/(double)a;
            tmp.ai=a;
            tmp.bi=b;
            v.push_back(tmp);
        }
    }

    sort(v.begin(),v.end(),comp);

    for(int i=0;i<v.size();i++){
        ans+=(v[i].ai*ans)+v[i].bi;
        ans%=40000;
    }
    ans+=zeroA;
    ans%=40000;

    cout << ans;

}
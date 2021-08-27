#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct flower{
    int stm;
    int std;
    int edm;
    int edd;
};

bool comp(flower x,flower y){
    bool ret=false;
    if(x.stm<y.stm) ret=true;
    if(x.stm==y.stm && x.std<y.std) ret=true;
    return ret;
}

int N, ans;
vector<flower> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        struct flower tmp;
        cin >> tmp.stm >> tmp.std >> tmp.edm >> tmp.edd;
        v.push_back(tmp);
    }

    sort(v.begin(),v.end(),comp);

    int curm=3, curd=1, exist=0, maxm=0, maxd=0;
    for(int i=0;i<N;i++){
        if(v[i].edm<curm || (v[i].edm==curm && v[i].edd<=curd)) continue;
        else if(v[i].stm<curm || (v[i].stm==curm && v[i].std<=curd)){
            exist=1;
            if(v[i].edm>maxm || (v[i].edm==maxm && v[i].edd>maxd)){
                maxm=v[i].edm;
                maxd=v[i].edd;
            }
        }
        else{
            if(exist==0) break;
            else{
                ans++;
                curm=maxm;
                curd=maxd;
                if(curm==12){
                    exist=1;
                    break;
                }

                i--;
                exist=0;
                maxm=0;
                maxd=0;
            }
        }
    }

    if(exist==0) cout << 0;
    else{
        if(curm==12) cout << ans;
        else if(maxm==12) cout << ans+1;
        else cout << 0;
    }
}
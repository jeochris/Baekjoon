#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ticket{
    int where;
    int wi;
    int qi;
};

int N;
vector<ticket> v;

bool comp(ticket x,ticket y){
    bool ret=false;
    double a,b;
    a=x.wi/(double)(10000-x.qi);
    b=y.wi/(double)(10000-y.qi);

    if(a>b) ret=true;
    else if(a==b){
        if(x.where<y.where) ret=true;
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;

        struct ticket tmp;
        tmp.where=i+1;
        tmp.wi=a;
        tmp.qi=b;

        v.push_back(tmp);
    }

    sort(v.begin(),v.end(),comp);

    for(int i=0;i<N;i++) cout << v[i].where << " ";

}
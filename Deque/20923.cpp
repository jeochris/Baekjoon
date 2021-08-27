#include <iostream>
#include <deque>
using namespace std;

deque<int> d,s,dg,sg;
int N,M,a,b;

void check(){
    if((!dg.empty() && dg.front()==5) || (!sg.empty() && sg.front()==5)){
        while(!sg.empty()){
            d.push_back(sg.back());
            sg.pop_back();
        }
        while(!dg.empty()){
            d.push_back(dg.back());
            dg.pop_back();
        }
    }
    else if(!dg.empty() && !sg.empty() && dg.front()+sg.front()==5){
        while(!dg.empty()){
            s.push_back(dg.back());
            dg.pop_back();
        }
        while(!sg.empty()){
            s.push_back(sg.back());
            sg.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> a >> b;
        d.push_front(a);
        s.push_front(b);
    }

    for(int i=0;i<M;i++){
        if(i%2==0){
            dg.push_front(d.front());
            d.pop_front();
            if(d.empty()){
                cout << "su";
                return 0;
            }
            check();
        }
        else{
            sg.push_front(s.front());
            s.pop_front();
            if(s.empty()){
                cout << "do";
                return 0;
            }
            check();
        }
        
    }

    if(d.size()>s.size()) cout << "do";
    else if(d.size()<s.size()) cout << "su";
    else cout << "dosu";
}
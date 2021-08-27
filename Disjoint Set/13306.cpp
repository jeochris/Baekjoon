#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N, Q, finalP[200003], curP[200003], ques[400002][2];
stack<int> ans;

int Find(int x){
    if(curP[x]==-1) return x;
    return curP[x]=Find(curP[x]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    finalP[1]=-1;
    curP[1]=-1;
    for(int i=2;i<=N;i++){
        int tmp;
        cin >> tmp;
        finalP[i]=tmp;
        curP[i]=-1;
    }

    int which, v1, v2;
    for(int i=0;i<N+Q-1;i++){
        cin >> which;
        if(which==0){
            cin >> v1;
            ques[i][0]=v1;
        }
        else{
            cin >> v1 >> v2;
            ques[i][0]=v1;
            ques[i][1]=v2;
        }
    }

    // backward
    for(int i=N+Q-2;i>=0;i--){
        int v1=ques[i][0], v2=ques[i][1];
        if(v2==0){
            curP[v1]=finalP[v1];
        }
        else{
            if(Find(v1)==Find(v2)) ans.push(1);
            else ans.push(0);
        }
    }

    while(!ans.empty()){
        if(ans.top()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        ans.pop();
    }
}
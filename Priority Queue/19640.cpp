#include <iostream>
#include <queue>
using namespace std;

int N, M, K, ans=0;

struct worker{
    int D, H, L, num;
};

struct cmp{
    bool operator()(worker x,worker y){
        if(x.D!=y.D) return x.D<y.D;
        if(x.H!=y.H) return x.H<y.H;
        return x.L>y.L;
    }
};

queue<worker> line[100004];
priority_queue<worker,vector<worker>,cmp> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for(int i=1;i<=N;i++){
        int a,b;
        cin >> a >> b;

        worker tmp;
        tmp.D=a;
        tmp.H=b;
        if(i%M==0) tmp.L=M;
        else tmp.L=(i%M);
        tmp.num=i;

        if(i<=M) pq.push(tmp);
        else line[tmp.L].push(tmp);
    }

    while(pq.top().num!=(K+1)){
        int from;
        from=pq.top().L;
        pq.pop();

        if(!line[from].empty()){
            pq.push(line[from].front());
            line[from].pop();
        }

        ans++;

    }

    cout << ans;

}
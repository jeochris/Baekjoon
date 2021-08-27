#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M;
    int cnt[10];

    cin >> T;
    for(int i=0;i<T;i++){
        for(int j=1;j<10;j++) cnt[j]=0;
        deque<pair<int,int>> dq;

        cin >> N >> M;
        for(int j=0;j<N;j++){
            int tmp;
            cin >> tmp;
            cnt[tmp]++;
            dq.push_back({tmp,0});
        }
        dq[M].second=1;
        
        int step=0, next=0;
        for(int j=9;j>0;j--){
            while(cnt[j]>0){
                if(dq.front().first==j){
                    step++;
                    cnt[j]--;
                    if(dq.front().second==1){
                        cout << step << "\n";
                        next++;
                        break;
                    }
                    dq.pop_front();
                }
                else{
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
            }
            if(next) break;
        }

    }

}
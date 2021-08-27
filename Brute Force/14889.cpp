#include <iostream>
#include <algorithm>
using namespace std;

int N, ans=10000;
int score[22][22], team[21];

void check(int now,int step){
    team[now]=1;

    if(step==N/2){
        int fir=0, sec=0;
        for(int i=0;i<N;i++){
            if(team[i]==1){
                for(int j=0;j<N;j++){
                    if(team[j]==1) fir+=score[i][j];
                }
            }
            else{
                for(int j=0;j<N;j++){
                    if(team[j]==0) sec+=score[i][j];
                }
            }
        }
        ans=min(ans,abs(fir-sec));
    }
    else{
        for(int i=now+1;i<=step+N/2;i++){
            check(i,step+1);
        }
    }

    team[now]=0;
    return;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> score[i][j];
        }
    }

    check(0,1);
    cout << ans;

}
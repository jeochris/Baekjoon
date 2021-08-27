#include <iostream>
#include <deque>
using namespace std;

int N, K, L;
int board[105][105];
int wayx[4]={1,0,-1,0};
int wayy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) board[i][j]=1;
    }
    for(int i=0;i<K;i++){
        int ax,ay;
        cin >> ax >> ay;
        board[ay][ax]=3;
    }

    deque<pair<int,char>> dir;
    cin >> L;
    for(int i=0;i<L;i++){
        int dirs;
        char dird;
        cin >> dirs >> dird;
        dir.push_back({dirs,dird});
    }

    deque<pair<int,int>> bam;
    bam.push_back({1,1});
    board[1][1]=2;

    int curd=0;
    for(int sec=1;;sec++){
        int nextx=bam.front().first+wayx[curd];
        int nexty=bam.front().second+wayy[curd];
        if(board[nextx][nexty]==0 || board[nextx][nexty]==2){
            cout << sec;
            break;
        }

        bam.push_front({nextx,nexty});
        if(board[nextx][nexty]==1){
            board[bam.back().first][bam.back().second]=1;
            bam.pop_back();
        }
        board[nextx][nexty]=2;

        if(dir.front().first==sec){
            if(dir.front().second=='D') curd++;
            else curd--;
            if(curd==-1) curd=3;
            if(curd==4) curd=0;
            dir.pop_front();
        }

    }

}
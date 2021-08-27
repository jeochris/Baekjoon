#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[12][12];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<int> cases;

void dfs(int x,int y,int lev,int curSum){

    curSum=curSum*10+board[x][y];
    if(lev==6){
        cases.push_back(curSum);
        return;
    }

    for(int i=0;i<4;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>0 && ny>0 && nx<6 && ny<6){
            dfs(nx,ny,lev+1,curSum);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=1;i<6;i++){
        for(int j=1;j<6;j++) cin >> board[i][j];
    }

    for(int i=1;i<6;i++){
        for(int j=1;j<6;j++) dfs(i,j,1,0);
    }

    sort(cases.begin(),cases.end());

    int bef=cases[0], ans=1;
    for(int i=1;i<cases.size();i++){
        if(cases[i]!=bef){
            bef=cases[i];
            ans++;
        }
    }
    cout << ans;

}
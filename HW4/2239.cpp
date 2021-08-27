#include <iostream>
#include <deque>
#include <string>
using namespace std;

int sudo[9][9], ans=0;
deque<pair<int,int>> zero;
int sqx[3]={0,1,2}, sqy[3]={0,1,2};

void find_lowest(int zx,int zy){
    int cand[10]={0,};
    for(int i=0;i<9;i++){
        cand[sudo[zx][i]]=1;
        cand[sudo[i][zy]]=1;
    }
    int sqstx=(zx/3)*3, sqsty=(zy/3)*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cand[sudo[sqstx+sqx[i]][sqsty+sqy[j]]]=1;
        }
    }
    
    for(int i=1;i<10;i++)if(cand[i]==0){
        sudo[zx][zy]=i;
        zero.pop_front();
        
        if(!zero.empty()) find_lowest(zero.front().first,zero.front().second);
        else ans++;

        if(ans) return;
        else{
            zero.push_front({zx,zy});
            sudo[zx][zy]=0;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string line;
    for(int i=0;i<9;i++){
        cin >> line;
        for(int j=0;j<9;j++){
            sudo[i][j]=line[j]-'0';
            if(sudo[i][j]==0) zero.push_back({i,j});
        }
    }

    if(!zero.empty()) find_lowest(zero.front().first,zero.front().second);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++) cout << sudo[i][j];
        cout << "\n";
    }

}
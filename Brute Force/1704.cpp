#include <iostream>
#include <cmath>
using namespace std;

int M, N, arr[18][18], inp[18][18], ans=0;
int time[18][18], save[18][18], low=400;
int xway[4]={1,-1,0,0};
int yway[4]={0,0,1,-1};

void rev(int x,int y){
    arr[x][y]=1-arr[x][y];
    for(int i=0;i<4;i++) arr[x+xway[i]][y+yway[i]]=1-arr[x+xway[i]][y+yway[i]];
}

void checkLeft(int row){
    if(row==1){
        for(int i=1;i<=N;i++)if(time[1][i]) rev(1,i);
    }
    else{
        for(int i=1;i<=N;i++){
            if(arr[row-1][i]){
                time[row][i]=1;
                rev(row,i);
            }
            else time[row][i]=0;
        }
    }

    if(row==M){
        bool tmp=true;
        for(int i=1;i<=N;i++)if(arr[M][i]){
            tmp=false;
            break;
        }
        if(tmp) ans=1;
        else ans=0;
    }
    else checkLeft(row+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin >> inp[i][j];
            arr[i][j]=inp[i][j];
        }
    }

    int lastCheck=int(pow(2,N));

    for(int i=0;i<lastCheck;i++){
        int num=i, cur=lastCheck/2, x=1;
        while(x<=N){
            time[1][x]=int(num/cur);
            num=num%cur;
            cur/=2;
            x++;
        }
        checkLeft(1);

        int chk=0;
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                arr[i][j]=inp[i][j];
                if(ans) chk+=time[i][j];
            }
        }
        if(ans==1 && chk<low){
            for(int i=1;i<=M;i++){
                for(int j=1;j<=N;j++){
                    save[i][j]=time[i][j];
                }
            }
            low=chk;
        }
    }

    if(low==400) cout << "IMPOSSIBLE";
    else{
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++) cout << save[i][j] << " ";
            cout << "\n";
        }
    }

}
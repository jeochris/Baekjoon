#include <iostream>
#include <string>
using namespace std;

int N, M, arr[1003][1003], ans;
int psum[1004][1004];

int getArea(int sty,int stx,int edy,int edx){
    return psum[edy][edx]-psum[edy][stx-1]-psum[sty-1][edx]+psum[sty-1][stx-1];
}

void findMax(int sty,int stx){
    int cur=ans, bar=min(N-sty+1,M-stx+1);
    for(int i=ans+1;i<=bar;i++){
        if(getArea(sty,stx,sty+i-1,stx+i-1)==i*i) cur=i;
        else break;
    }
    ans=cur;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=1;i<=N;i++){
        string line;
        cin >> line;
        for(int j=1;j<=M;j++) arr[i][j]=line[j-1]-'0';
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+arr[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)if(arr[i][j]) findMax(i,j);
    }

    cout << ans*ans;

}
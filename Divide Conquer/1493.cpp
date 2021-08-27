#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int L, W, H, N, cube[21], ans;
bool haveAns=true;

void fill(int l,int w,int h){
    if(!haveAns) return;
    
    int minL=min(l,min(w,h));
    if(minL<=0) return;

    bool putIn=false;
    int curL=pow(2,20);
    
    for(int i=19;i>=0;i--){
        curL/=2;
        
        if(cube[i] && curL<=minL){
            cube[i]--;
            ans++;
            fill(l-curL,w,h);
            fill(curL,h,w-curL);
            fill(curL,h-curL,curL);
            if(haveAns) putIn=true;
            break;
        }
    }

    if(!putIn) haveAns=false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> W >> H;
    cin >> N;

    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        cube[x]=y;
    }

    fill(L,W,H);
    if(!haveAns) cout << -1;
    else cout << ans;

}
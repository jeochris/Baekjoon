#include <iostream>
#include <algorithm>
using namespace std;

int N, cur[2][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        int a[3];
        for(int j=0;j<3;j++) cin >> a[j];

        // i=0 - max / i=1 - min
        int max1=max(cur[0][0], cur[0][1]);
        int max2=max(cur[0][1], cur[0][2]);
        int min1=min(cur[1][0], cur[1][1]);
        int min2=min(cur[1][1], cur[1][2]);

        cur[0][0]=max1+a[0];
        cur[0][1]=max(max1,max2)+a[1];
        cur[0][2]=max2+a[2];

        cur[1][0]=min1+a[0];
        cur[1][1]=min(min1,min2)+a[1];
        cur[1][2]=min2+a[2];

    }

    int ans1=0,ans2=2e9;
    for(int i=0;i<3;i++){
        ans1=max(ans1,cur[0][i]);
        ans2=min(ans2,cur[1][i]);
    }

    cout << ans1 << " " << ans2;

}
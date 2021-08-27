#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M, arr[104][104];
long long int ans;
int psum[104][104];

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

    for(int i=1;i<M-1;i++){
        for(int j=i+1;j<M;j++){
            long long int b=psum[N][j]-psum[N][i];
            long long int c=psum[N][M]-psum[N][j];
            ans=max(ans,psum[N][i]*b*c);
        }
    }
    for(int i=1;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            long long int b=psum[j][M]-psum[i][M];
            long long int c=psum[N][M]-psum[j][M];
            ans=max(ans,psum[i][M]*b*c);
        }
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<M;j++){
            long long int a=psum[i][j];
            long long int b=psum[i][M]-a;
            long long int c=psum[N][j]-a;
            long long int d=psum[N][M]-a-b-c;

            ans=max(ans,(a+b)*c*d);
            ans=max(ans,(a+c)*b*d);
            ans=max(ans,(b+d)*a*c);
            ans=max(ans,(c+d)*a*b);
        }
    }
    cout << ans;

}
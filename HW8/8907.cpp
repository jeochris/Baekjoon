#include <iostream>
using namespace std;

int T, adj[1002][1002];

void findTri(){
    int N, input, sumAngle=0;
    
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            cin >> input;
            adj[i][j]=input;
            adj[j][i]=input;
        }

        int blue=0, red=0;
        for(int j=1;j<=N;j++)if(i!=j){
            if(adj[i][j]) red++;
            else blue++;
        }

        sumAngle+=(red*blue);
    }

    int ans=N*(N-1)*(N-2)/6-(sumAngle/2);

    cout << ans << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i=0;i<T;i++) findTri();

}
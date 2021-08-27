#include <iostream>
#include <algorithm>
using namespace std;

int N, cnt[4], shape[100004], ans=2e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> shape[i];
        cnt[shape[i]]++;
    }

    for(int i=1;i<4;i++){
        int sec1=i;
        for(int j=1;j<4;j++)if(j!=i){
            int sec2=j, sec3=6-i-j, num=0;
            int subcnt[4][4]={0,};

            for(int k=0;k<N;k++){
                if(k<cnt[sec1]) subcnt[1][shape[k]]++;
                else if(k>=N-cnt[sec3]) subcnt[3][shape[k]]++;
                else subcnt[2][shape[k]]++;
            }

            while(subcnt[3][sec1] && subcnt[1][sec3]){
                subcnt[3][sec1]--;
                subcnt[1][sec3]--;
                subcnt[3][sec3]++;
                subcnt[1][sec1]++;
                num++;
            }
            while(subcnt[3][sec1]){
                subcnt[3][sec1]--;
                subcnt[1][sec2]--;
                subcnt[3][sec2]++;
                subcnt[1][sec1]++;
                num++;
            }

            while(subcnt[2][sec1] && subcnt[1][sec2]){
                subcnt[2][sec1]--;
                subcnt[1][sec2]--;
                subcnt[2][sec2]++;
                subcnt[1][sec1]++;
                num++;
            }
            while(subcnt[2][sec1]){
                subcnt[2][sec1]--;
                subcnt[1][sec3]--;
                subcnt[2][sec3]++;
                subcnt[1][sec1]++;
                num++;
            }

            num+=subcnt[2][sec3];
            ans=min(ans,num);
        }
    }

    cout << ans;

}
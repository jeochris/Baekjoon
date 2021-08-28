#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans=0;
long long int X;
vector<long long int> C;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> X;
    for(int i=0;i<N;i++){
        long long int tmp;
        cin >> tmp;
        C.push_back(tmp);
    }

    sort(C.begin(),C.end());

    int firstAll=N, st=0, ed=-1;
    for(int i=N-1;i>=0;i--){
        if(C[i]==X){
            firstAll--;
            ans++;
        }
        else{
            ed=i;
            break;
        }
    }

    bool haveFound;
    for(int i=ed;i>=0;i--){
        haveFound=false;
        if(i<=st) break;
        for(int j=st;j<i;j++){
            if((C[i]+C[j])*2>=X){
                ans++;
                st=j+1;
                firstAll-=2;
                haveFound=true;
                break;
            }
        }
        if(!haveFound) break;
    }

    ans+=firstAll/3;
    cout << ans;

}
#include <iostream>
#include <algorithm>
using namespace std;

string found;
int num[10], sum=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> found;
    for(int i=0;i<found.size();i++){
        num[found[i]-'0']++;
        sum+=found[i]-'0';
    }

    if(num[0]==0 || sum%3!=0){
        cout << -1;
        return 0;
    }

    for(int j=9;j>=0;j--){
        while(num[j]!=0){
            cout << j;
            num[j]--;
        }
    }

}
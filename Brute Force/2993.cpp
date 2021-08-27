#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string word, tmp, min;

    cin >> word;
    min=word;
    int size=word.size();
    
    for(int i=1;i<=size-2;i++){
        tmp=word;
        reverse(tmp.begin(),tmp.begin()+i);
        for(int j=1;j<=size-i-1;j++){
            reverse(tmp.begin()+i,tmp.begin()+i+j);
            reverse(tmp.begin()+i+j,tmp.end());
            if(tmp<min) min=tmp;
            reverse(tmp.begin()+i,tmp.begin()+i+j);
            reverse(tmp.begin()+i+j,tmp.end());
        }
    } 

    cout << min;
}
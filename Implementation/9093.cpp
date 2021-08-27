#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int T;
string sen;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    cin.ignore();

    for(int i=0;i<T;i++){
        getline(cin, sen);
        int st=0;
        for(int j=0;j<sen.size();j++)if(sen[j]==' '){
            reverse(sen.begin()+st,sen.begin()+j);
            st=j+1;
        }
        reverse(sen.begin()+st,sen.end());
        cout << sen << "\n";
    }

}
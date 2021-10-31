#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    getline(cin,str);

    for(int i=1;i<str.length();i++){
        if(str[i]=='2'){
            if(str[i-1]=='D' || str[i-1]=='d'){
                cout << "D2";
                return 0;
            }
        }
    }
    cout << "unrated";

}
#include <iostream>
#include <string>
using namespace std;

string str;

bool checkPelin(int st,int len){
    if(len==1) return true;
    for(int i=st;i<st+len;i++){
        if(str[i]!=str[len-1+st*2-i]) return false;
    }
    if(len%2==0) return (checkPelin(st,len/2) && checkPelin(st+len/2,len/2));
    else return (checkPelin(st,len/2) && checkPelin(st+(len-1)/2+1,len/2));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    if(checkPelin(0,str.length())){
        cout << "AKARAKA";
    }
    else cout << "IPSELENTI";
}
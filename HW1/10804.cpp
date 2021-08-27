#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int fir,sec;
    int cards[21];
    
    for(int i=1;i<=20;i++){
        cards[i]=i;
    }

    for(int i=0;i<10;i++){
        cin >> fir >> sec;
        for(int j=fir;j<=(fir+sec)/2;j++){
            swap(cards[j],cards[fir+sec-j]);
        }
    }

    for(int i=1;i<=20;i++) cout << cards[i] << " ";
}
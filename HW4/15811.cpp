#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string word[3];

int existAlpha[26], used[10], numAlpha[26], ans;

vector<int> valpha;

int getNum(int idx){
    int sum=0;
    for(int i=0;i<word[idx].length();i++){
        sum=sum*10+numAlpha[word[idx][i]-'A'];
    }
    return sum;
}

void putNum(int idx){
    if(idx==valpha.size()){
        if(getNum(0)+getNum(1)==getNum(2)){
            ans=1;
            cout << "YES";
        }
        else return;
    }

    for(int i=0;i<10;i++)if(used[i]==0){
        numAlpha[valpha[idx]]=i;
        used[i]=1;
        putNum(idx+1);
        numAlpha[valpha[idx]]=0;
        used[i]=0;
        if(ans) break;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<3;i++){
        cin >> word[i];
        for(int j=0;j<word[i].length();j++) existAlpha[word[i][j]-'A']=1;
    }

    for(int i=0;i<26;i++){
        if(existAlpha[i]) valpha.push_back(i);
    }

    putNum(0);
    if(ans==0) cout << "NO";
}
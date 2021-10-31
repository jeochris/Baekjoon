#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
char arr[1252][1252];
vector<pair<pair<int,int>,pair<int,string>>> fossil;

int findLength(int y,int x){
    int tr1=0, tr2=0;
    for(int i=y;i<=N;i++){
        if(arr[i][x]=='#') tr1++;
        else break;
    }
    for(int i=x;i<=N;i++){
        if(arr[y][i]=='#') tr2++;
        else break;
    }
    return max(tr1,tr2);
}

string findDir(int y,int x,int len){
    if(arr[y][x+1]=='.') return "UL";
    if(arr[y][x+len-2]=='.') return "UR";
    if(arr[y+1][x]=='.') return "LU";
    if(arr[y+1][x+len-1]=='.') return "RU";
    if(arr[y+len-2][x]=='.') return "LD";
    if(arr[y+len-2][x+len-1]=='.') return "RD";
    if(arr[y+len-1][x+1]=='.') return "DL";
    if(arr[y+len-1][x+len-2]=='.') return "DR";
    return 0;
}

void makeDot(int y,int x,int len){
    for(int i=y;i<y+len;i++){
        for(int j=x;j<x+len;j++){
            arr[i][j]='.';
        }
    }
}

bool compare(pair<pair<int,int>,pair<int,string>> a,pair<pair<int,int>,pair<int,string>> b){
    if(a.first.first!=b.first.first) return a.first.first<b.first.first;
    else return a.first.second<b.first.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    string str;
    for(int i=1;i<=N;i++){
        cin >> str;
        for(int j=0;j<N;j++){
            arr[i][j+1]=str[j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(arr[i][j]=='#'){
                int len=findLength(i,j);
                string dir=findDir(i,j,len);
                fossil.push_back({{i+(len-1)/2,j+(len-1)/2},{len,dir}});
                makeDot(i,j,len);
            }
        }
    }

    sort(fossil.begin(),fossil.end(),compare);

    cout << fossil.size() << "\n";
    for(int i=0;i<fossil.size();i++){
        cout << fossil[i].first.first << " " << fossil[i].first.second << " " << fossil[i].second.first << " ";
        cout << fossil[i].second.second << "\n";
    }

}
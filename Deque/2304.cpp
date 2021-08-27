#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, max_h=0, area=0;
vector<pair<int,int>> col, lft, rht;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        int l, h;
        cin >> l >> h;
        max_h=max(h,max_h);
        col.push_back({l,h});
    }
    sort(col.begin(),col.end());

    int max_c=0;
    for(int i=0;i<N;i++){
        if(col[i].second==max_h){
            lft.push_back(col[i]);
            break;
        }
        if(col[i].second>max_c){
            lft.push_back(col[i]);
            max_c=col[i].second;
        }
    }

    max_c=0;
    for(int i=N-1;i>=0;i--){
        if(col[i].second==max_h){
            col[i].first++;
            rht.push_back(col[i]);
            break;
        }
        if(col[i].second>max_c){
            col[i].first++;
            rht.push_back(col[i]);
            max_c=col[i].second;
        }
    }

    for(int i=0;i<lft.size();i++)if(i+1!=lft.size()){
        area+=(lft[i+1].first-lft[i].first)*lft[i].second;
    }
    for(int i=0;i<rht.size();i++)if(i+1!=rht.size()){
        area+=(rht[i].first-rht[i+1].first)*rht[i].second;
    }
    area+=max_h*(rht[rht.size()-1].first-lft[lft.size()-1].first);

    cout << area;

}
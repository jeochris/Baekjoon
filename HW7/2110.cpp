#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, ans;
vector<int> house;

bool check(int dis){
    int left=C-1, lastLoc=house[0];
    for(int i=1;i<house.size();i++){
        if(house[i]>=lastLoc+dis){
            left--;
            lastLoc=house[i];
            if(left==0) return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        house.push_back(tmp);
    }
    sort(house.begin(),house.end());

    int s=1;
    int e=1e9;
    while(s<=e){
        int mid=(s+e)/2;
        if(check(mid)){
            ans=max(ans,mid);
            s=mid+1;
        }
        else e=mid-1;
    }
    cout << ans;

}
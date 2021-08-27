#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, L, ans=1000;
vector<int> exist;

bool check(int want){
    int checkUntil=0, left=M, cur=0;
    while(checkUntil+want<L){
        checkUntil+=want;
        if(cur<exist.size() && exist[cur]<=checkUntil){
            checkUntil=exist[cur];
            cur++;
        }
        else{
            left--;
            if(left<0) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> L;

    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        exist.push_back(tmp);
    }

    sort(exist.begin(),exist.end());

    int s=0, e=1000;
    while(s<=e){
        int mid=(s+e)/2;
        if(check(mid)){
            ans=min(ans,mid);
            e=mid-1;
        }
        else s=mid+1;
    }

    cout << ans;

}
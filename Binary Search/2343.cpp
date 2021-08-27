#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> lesson;

bool check(int len){
    int stck=0, used=0;
    for(int i=0;i<lesson.size();i++){
        if(lesson[i]>len) return false;
        stck+=lesson[i];
        if(stck>len){
            used++;
            stck=0;
            i--;
        }
    }
    if(used+1<=M) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        lesson.push_back(tmp);
    }

    int s=0, e=1e9, ans;
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
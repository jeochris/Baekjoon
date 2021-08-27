#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int findBiggest(int st,int ed){
    if(ed<st) return 0;
    int mid=(st+ed)/2, bottom=1;
    int ret=v[mid], height=v[mid], curL=mid, curR=mid;

    while(curL!=st || curR!=ed){
        bottom++;
        if(curL==st){
            curR++;
            height=min(height,v[curR]);
        }
        else if(curR==ed){
            curL--;
            height=min(height,v[curL]);
        }
        else{
            if(v[curL-1]>v[curR+1]){
                curL--;
                height=min(height,v[curL]);
            }
            else{
                curR++;
                height=min(height,v[curR]);
            }
        }
        ret=max(ret,height*bottom);
    }

    ret=max(ret,findBiggest(st,mid-1));
    ret=max(ret,findBiggest(mid+1,ed));

    return ret;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    cout << findBiggest(0,N-1);

}
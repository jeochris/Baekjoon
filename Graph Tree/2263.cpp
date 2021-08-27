#include <iostream>
#include <vector>
using namespace std;

int n, input;
vector<int> in, post, ans;

void findRoot(int sti,int stp,int size){
    if(size==0) return;

    ans.push_back(post[stp+size-1]);
    int idx;
    for(int i=sti;i<sti+size;i++){
        if(in[i]==post[stp+size-1]){
            idx=i;
            break;
        }
    }
    findRoot(sti,stp,idx-sti);
    findRoot(idx+1,stp+idx-sti,size-idx+sti-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> input;
        in.push_back(input);
    }
    for(int i=0;i<n;i++){
        cin >> input;
        post.push_back(input);
    }

    findRoot(0,0,n);
    for(int i=0;i<n;i++) cout << ans[i] << " ";

}
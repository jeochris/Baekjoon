#include <iostream>
#include <string>
#include <deque>
using namespace std;

int ans=0;
string line;
deque<int> dq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> line;
    for(int i=0;i<line.length();i++){
        if(line[i]=='(') dq.push_back(-1);
        else{
            if(dq.back()<0){
                dq.pop_back();
                dq.push_back(1);
                if(dq.size()==1) dq.pop_back();
            }
            else{
                int tmp=0;
                while(dq.back()>0){
                    tmp+=dq.back();
                    dq.pop_back();
                }
                dq.pop_back();
                ans+=(tmp+1);
                dq.push_back(tmp);
                if(dq.size()==1) dq.pop_back();
            }
        }
    }
    cout << ans;

}
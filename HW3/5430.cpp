#include <iostream>
#include <string>
#include <deque>
using namespace std;

int T, n;
string calc, arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i=0;i<T;i++){
        deque<int> num;
        cin >> calc >> n >> arr;

        int tmp=0;
        for(int j=1;j<arr.length();j++){
            if(arr[j]==',' || (j!=1 && arr[j]==']')){
                num.push_back(tmp);
                tmp=0;
            }
            else{
                tmp=tmp*10+arr[j]-'0';
            }
        }

        int cur=0, err=0;
        for(int j=0;j<calc.length();j++){
            if(calc[j]=='R') cur++;
            else if(num.empty()){
                cout << "error\n";
                err=1;
                break;
            }
            else{
                if(cur%2==0) num.pop_front();
                else num.pop_back();
            }
        }

        if(err==0){
            cout << "[";
            while(!num.empty()){
                if(cur%2==0){
                    cout << num.front();
                    if(num.size()>1) cout << ",";
                    num.pop_front();
                }
                else{
                    cout << num.back();
                    if(num.size()>1) cout << ",";
                    num.pop_back();
                }
            }
            cout << "]\n";
        }
    }

}
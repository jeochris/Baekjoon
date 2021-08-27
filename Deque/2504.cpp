#include <iostream>
#include <string>
#include <deque>
using namespace std;

string line;
deque<int> dq;

int finish(){
    cout << 0;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tmp;

    cin >> line;
    for(int i=0;i<line.length();i++){
        if(line[i]=='(') dq.push_back(-1);
        else if(line[i]=='[') dq.push_back(-2);

        else if(line[i]==')'){
            if(dq.empty() || dq.back()==-2) return finish();
            else if(dq.back()==-1){
                dq.pop_back();
                dq.push_back(2);
            }
            else if(dq.back()>0){
                int tmp=0;
                while(dq.back()>0){
                    tmp+=dq.back();
                    dq.pop_back();
                    if(dq.empty() || dq.back()==-2) return finish();
                }
                dq.pop_back();
                dq.push_back(tmp*2);
            }
        }

        else if(line[i]==']'){
            if(dq.empty() || dq.back()==-1) return finish();
            else if(dq.back()==-2){
                dq.pop_back();
                dq.push_back(3);
            }
            else if(dq.back()>0){
                int tmp=0;
                while(dq.back()>0){
                    tmp+=dq.back();
                    dq.pop_back();
                    if(dq.empty() || dq.back()==-1) return finish();
                }
                dq.pop_back();
                dq.push_back(tmp*3);
            }
        }
        else return finish();
    }
    int sum=0;
    for(int i=0;i<dq.size();i++){
        if(dq[i]<0) return finish();
        sum+=dq[i];
    }
    cout << sum;

}
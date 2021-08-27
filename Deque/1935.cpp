#include <iostream>
#include <string>
#include <deque>
using namespace std;

int N;
string line;
double num[27];
deque<double> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> line;
    for(int i=0;i<N;i++) cin >> num[i];

    for(int i=0;i<line.length();i++){
        if(line[i]>='A' && line[i]<='Z'){
            ans.push_back(num[line[i]-'A']);
        }
        else{
            double a=ans.back();
            ans.pop_back();
            double b=ans.back();
            ans.pop_back();

            if(line[i]=='+') ans.push_back(b+a);
            else if(line[i]=='-') ans.push_back(b-a);
            else if(line[i]=='/') ans.push_back(b/a);
            else ans.push_back(a*b);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << ans.back();

}
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj_list[13];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<12;i++){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    for(int i=1;i<=12;i++){
        if(adj_list[i].size()==3){
            int sum=0;
            for(int j=0;j<3;j++){
                sum+=adj_list[adj_list[i][j]].size();
            }
            if(sum==6){
                cout << i;
                break;
            }
        }
    }

}
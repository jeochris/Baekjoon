#include <iostream>
#include <string>
using namespace std;

int N, M, first[1000003];
pair<int,int> stat[1000003];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> first[i];
    }
    for(int i=0;i<N;i++){
        if(i==0) stat[first[i]].first=first[N-1];
        else stat[first[i]].first=first[i-1];

        if(i==N-1) stat[first[i]].second=first[0];
        else stat[first[i]].second=first[i+1];
    }

    for(int i=0;i<M;i++){
        string ques;
        cin >> ques;
        
        int a,b;
        if(ques=="BN"){
            cin >> a >> b;
            cout << stat[a].second << "\n";

            stat[stat[a].second].first=b;
            stat[b].second=stat[a].second;
            stat[b].first=a;
            stat[a].second=b;
        }
        else if(ques=="BP"){
            cin >> a >> b;
            cout << stat[a].first << "\n";

            stat[stat[a].first].second=b;
            stat[b].second=a;
            stat[b].first=stat[a].first;
            stat[a].first=b;
        }
        else if(ques=="CP"){
            cin >> a;
            cout << stat[a].first << "\n";

            stat[a].first=stat[stat[a].first].first;
            stat[stat[a].first].second=a;
        }
        else{
            cin >> a;
            cout << stat[a].second << "\n";

            stat[a].second=stat[stat[a].second].second;
            stat[stat[a].second].first=a;
        }
    }

}
#include <iostream>
#include <string>
using namespace std;

int N, Q;
int island[40003], city[1000003];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int cur=1;
    for(int i=1;i<=N;i++){
        int v, e;
        cin >> v >> e;
        for(int j=0;j<e;j++){
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
        }
        for(int k=cur;k<cur+v;k++){
            city[k]=i;
        }
        island[i]=v-e;
        cur+=v;
    }

    cin >> Q;
    for(int i=0;i<Q;i++){
        int ques, a, b;
        cin >> ques;
        if(ques==1){
            cin >> a;
            cout << island[a] << "\n";
        }
        else if(ques==2){
            cin >> a >> b;
            island[city[a]]++;
        }
        else{
            cin >> a >> b;
            island[city[a]]--;
        }
    }

}
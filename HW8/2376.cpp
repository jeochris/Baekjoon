#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, leaf[1002], dis;
vector<pair<int,int>> parent;

void makeTree(){
    cin >> N;
    parent.push_back({1,0});
    parent.push_back({0,0});
    leaf[1]=0;
    int beforeLeaf=0;

    for(int i=2;i<=N;i++){
        int dis;
        cin >> dis;
        
        int gotoUnfilled=parent[beforeLeaf].first;
        dis--;

        bool allFilled=false;
        while(parent[gotoUnfilled].second==1){
            if(parent[gotoUnfilled].first==0){
                allFilled=true;
                break;
            }
            gotoUnfilled=parent[gotoUnfilled].first;
            dis--;
        }

        if(allFilled){
            parent[gotoUnfilled].first=beforeLeaf+1;
            pair<int,int> newRoot;
            newRoot.first=0;
            newRoot.second=1;
            parent.push_back(newRoot);
            gotoUnfilled=beforeLeaf+1;
            dis--;
        }

        int startFrom=gotoUnfilled;
        parent[gotoUnfilled].second=1;

        while(dis--){
            pair<int,int> more;
            more.first=startFrom;
            more.second=0;
            parent.push_back(more);
            startFrom=parent.size()-1;
        }

        beforeLeaf=startFrom;
        leaf[i]=beforeLeaf;

    }

}

int calDistance(int x,int y){
    deque<int> pathX, pathY;
    int curX=parent[leaf[x]].first;
    int curY=parent[leaf[y]].first;

    while(curX){
        pathX.push_back(curX);
        curX=parent[curX].first;
    }
    while(curY){
        pathY.push_back(curY);
        curY=parent[curY].first;
    }

    while(!pathX.empty() && !pathY.empty() && pathX.back()==pathY.back()){
        pathX.pop_back();
        pathY.pop_back();
    }

    return pathX.size()+pathY.size()+2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    makeTree();

    int a,b;
    cin >> a >> b;
    cout << calDistance(a,b);

}
#include <iostream>
#include <algorithm>
using namespace std;

int N;
struct person{
    string name;
    int kor;
    int eng;
    int mat;
};

struct person stud[100005];

bool compare(person a,person b){
    if(a.kor!=b.kor) return a.kor>b.kor;
    if(a.eng!=b.eng) return a.eng<b.eng;
    if(a.mat!=b.mat) return a.mat>b.mat;
    return a.name<b.name;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0;i<N;i++) cin >> stud[i].name >> stud[i].kor >> stud[i].eng >> stud[i].mat;

    sort(stud,stud+N,compare);
    for(int i=0;i<N;i++) cout << stud[i].name << "\n";

}
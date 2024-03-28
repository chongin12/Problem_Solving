#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    int dasom; cin>>dasom;
    vector<int> v;
    v.push_back(-1);
    for(int i=1; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    int cnt=0;
    while(1){
        int midx=0;
        for(int i=0; i<v.size(); ++i){
            if(v[midx]<v[i]) midx=i;
        }
        if(dasom>v[midx]) break;
        dasom++;
        v[midx]--;
        cnt++;
    }
    cout << cnt << '\n';
}
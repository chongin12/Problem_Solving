#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int res[101];
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back({a,i});
    }
    stable_sort(v.begin(), v.end());
    for(int i=0; i<v.size(); ++i){
        res[v[i].second]=i;
    }
    for(int i=0; i<v.size(); ++i){
        cout << res[i] << ' ';
    }
    cout << '\n';
}
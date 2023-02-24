#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<pair<int,int> > v;
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        while(!v.empty() && v.back().first<a){
            v.pop_back();
        }
        if(v.empty()) cout << "0 ";
        else cout << v.back().second << ' ';
        v.push_back({a,i});
    }
    cout << '\n';
}
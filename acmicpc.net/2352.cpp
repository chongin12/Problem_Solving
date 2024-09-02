#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        auto pos = lower_bound(v.begin(), v.end(), a) - v.begin();
        if(pos == v.size()) v.push_back(a);
        else v[pos]=a;
    }
    cout << v.size() << '\n';
}
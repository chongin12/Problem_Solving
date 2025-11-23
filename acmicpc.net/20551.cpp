#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<M; ++i){
        int a; cin>>a;
        auto it=lower_bound(v.begin(), v.end(), a)-v.begin();
        if(it<v.size() && v[it]==a) cout << it << '\n';
        else cout << "-1\n";
    }
}
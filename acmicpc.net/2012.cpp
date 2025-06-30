#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Node {
    ll num, goal;
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    vector<Node> v;
    for(ll i=1; i<=N; ++i){
        ll a; cin>>a;
        v.push_back({i, a});
    }
    sort(v.begin(), v.end(), [](Node a, Node b){
        return a.goal<b.goal;
    });
    ll ret=0;
    for(ll i=0; i<v.size(); ++i){
        ll idx=i+1;
        ret+=abs(idx-v[i].goal);
    }
    cout << ret << '\n';
}
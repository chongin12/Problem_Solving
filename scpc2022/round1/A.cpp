#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct node {
    ll p,val;
    node(ll p, ll val):p(p),val(val){} 
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        int N; cin>>N;
        vector<node> v;
        vector<node> ori;
        for(int i=0; i<N; ++i){
            ll p; cin>>p;
            v.push_back(node(p,0));
        }
        for(int i=0; i<N; ++i){
            ll val; cin>>val;
            v[i].val=val;
            ori.push_back(v[i]);
        }
        stable_sort(v.begin(), v.end(), [](node a, node b){
            return a.val<b.val;
        });
        ll res=0;
        for(int i=0; i<N; ++i){
            res+=abs(v[i].p-ori[i].p);
        }
        cout << "Case #"<<t<<"\n";
        cout << res << '\n';
    }
}
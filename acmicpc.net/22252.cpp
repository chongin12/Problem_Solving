#include <bits/stdc++.h>
using namespace std;
using ll=long long;
map<string, ll> id;
ll idcnt=0;
priority_queue<ll> pq[100010];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll Q; cin>>Q;
    ll res=0;
    while(Q--){
        ll ch; cin>>ch;
        if(ch==1){
            string s; cin>>s;
            ll sid=id[s];
            if(sid==0){
                id[s]=++idcnt;
                sid=idcnt;
            }
            ll n; cin>>n;
            for(ll i=0; i<n; ++i){
                ll a; cin>>a;
                pq[sid].push(a);
            }
        }
        else{
            string s; cin>>s;
            ll k; cin>>k;
            while(k && !pq[id[s]].empty()){
                res+=pq[id[s]].top();
                pq[id[s]].pop();
                k--;
            }
        }
    }
    cout << res << '\n';
}
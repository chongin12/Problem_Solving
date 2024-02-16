#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie();
    ll N; cin>>N;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    ll res=0;
    for(ll i=0; i<=N; ++i){
        ll a; 
        if(i==N) a=1000000001;
        else cin>>a;
        // cout << "a : " << a << '\n';
        while(!pq.empty()){
            if(pq.top().first <= a){
                res+=i-pq.top().second-1;
                // cout << "res += " << i-pq.top().second-1 << '\n';
                pq.pop();
            }
            else{
                break;
            }
        }
        pq.push({a,i});
    }
    cout << res << '\n';
}
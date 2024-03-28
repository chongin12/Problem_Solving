#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, T, P; cin>>N>>T>>P;
    priority_queue<ll> pq;
    ll res=0;
    ll w=0; // 현재 돌의 총 무게 (pq에 있는 돌 무게 합)
    for(ll i=0; i<N; ++i){
        while(w+i*P>T && !pq.empty()){
            w-=pq.top();
            pq.pop();
        }
        if(w+i*P>T) break;
        ll a; cin>>a;
        if(w+i*P+a<=T){
            pq.push(a);
            w+=a;
            res=max(res,(ll)pq.size());
        }
        else if(!pq.empty()) {
            //원래 있는거 빼기
            ll m=pq.top();
            if(m>a && w+i*P+a-m<=T){
                pq.pop();
                pq.push(a);
                w-=m;
                w+=a;
            }
        }
        
    }
    cout << res << '\n';
}
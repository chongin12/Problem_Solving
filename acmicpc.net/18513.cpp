#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
map<ll,bool> visited;
int main(){
    ll N, K; cin>>N>>K;
    queue<pii> q;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a;
        q.push({a,0});
        visited[a]=true;
    }
    ll res=0;
    ll cnt=0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(!visited[cur.first+1]){
            visited[cur.first+1] = true;
            res+=cur.second+1;
            cnt++;
            q.push({cur.first+1, cur.second+1});
        }
        if(cnt==K) break;
        if(!visited[cur.first-1]){
            visited[cur.first-1] = true;
            res+=cur.second+1;
            cnt++;
            q.push({cur.first-1, cur.second+1});
        }
        if(cnt==K) break;
    }
    cout << res << '\n';
}
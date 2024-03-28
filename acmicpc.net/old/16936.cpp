// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;
using ll=long long;
vector<ll> G[101];
ll in[101];
ll minOutIdx=0;
ll visited[101];
ll N;
vector<ll> res;
bool fin=false;
void dfs(ll x, ll cnt){
    if(fin) return;
    if(cnt==N+1){
        fin=true;
        return;
    }
    visited[x]=1;
    res.push_back(x);
    for(auto it:G[x]){
        if(visited[it]) continue;
        dfs(it, cnt+1);
        if(fin) return;
    }
    res.pop_back();
    visited[x]=0;
}
int main(){
    cin>>N;
    vector<ll> v(N);
    for(ll i=0; i<N; ++i){
        cin>>v[i];
    }
    for(ll i=0; i<N; ++i){
        for(ll j=0; j<N; ++j){
            if(i==j) continue;
            if(v[i]*2==v[j]) G[i].push_back(j), in[j]++;
            if(v[i]%3==0 && v[i]/3==v[j]) G[i].push_back(j), in[j]++;
        }
    }
    for(ll i=1; i<N; ++i){
        if(in[minOutIdx]>in[i]) minOutIdx=i;
    }
    dfs(minOutIdx, 1);
    for(ll i=0; i<N; ++i){
        cout << v[res[i]] << " ";
    }
    cout << '\n';
}
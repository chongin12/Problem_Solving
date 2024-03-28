#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll MN=500001;
ll dp[2][MN];
bool sieve[MN];
vector<ll> prime;
int main(){
    for(ll i=2; i*i<MN; ++i){
        if(sieve[i]) continue;
        for(ll j=i*i; j<MN; j+=i){
            sieve[j]=true;
        }
    }
    for(ll i=2; i<MN; ++i){
        if(!sieve[i]) prime.push_back(i);
    }
    ll N; cin>>N;
    vector<ll> temp;
    vector<pair<ll,ll> > v;
    v.push_back({-1,0});
    for(int i=0; i<N; ++i){
        ll a; cin>>a; temp.push_back(a);
    }
    sort(temp.begin(), temp.end());
    for(ll i=1; i<=N; ++i){
        ll a=temp[i-1];
        if(a==v.back().first) v.back().second++;
        else v.push_back({a,1});
    }
    sort(v.begin(), v.end());
    for(int i=1; i<=v.size()-1; ++i){
        for(int j=0; j<MN; ++j){
            dp[i%2][j]=0;
        }
        ll count=v[i].second;
        ll num=v[i].first;
        for(ll j=0; j<MN; ++j){
            dp[i%2][j]+=dp[(i-1)%2][j];
        }
        for(ll cnt=1; cnt<=count; ++cnt){
            num=cnt*v[i].first;
            dp[i%2][num]+=1;
            for(ll j=num; j<MN; ++j){
                dp[i%2][j]+=dp[(i-1)%2][j-num];
            }
        }
    }
    ll res=0;
    for(auto it:prime){
        res+=dp[(v.size()-1)%2][it];
    }
    cout << res << '\n';
}
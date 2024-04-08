// 누적합을 구한 후 나온 것들을 모두 정렬.
// lower_bound, upper_bound로 구하기
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const ll INF = 987654321;
ll acc[200001];
vector<pll> v;
bool comp(pll &a, pll &b){
    return a.x < b.x;
}
int main(){
    ll N, K; cin>>N>>K;
    for(ll i=1; i<=N; ++i){
        ll a; cin>>a;
        acc[i]=acc[i-1]+a;
    }
    for(ll i=1; i<=N; ++i){
        v.push_back({acc[i],i});
    }
    sort(v.begin(), v.end());
    // for(auto it:v){
    //     cout << it.x << ", " << it.y << '\n';
    // }
    // cout << '\n';
    ll res=0;
    for(int i=0; i<v.size(); ++i){
        if(v[i].x==K) res++;
        auto up = upper_bound(v.begin(), v.end(), pll(v[i].x-K, v[i].y-1)) - v.begin();
        auto lo = lower_bound(v.begin(), v.end(), pll(v[i].x-K, 0)) - v.begin();
        // cout << "tofind : " << v[i].x-K << " | lo : " << lo << ", up : " << up << '\n';
        res+=up - lo; // it + (-upperbound) = K
    }
    cout << res << '\n';
}
/*
2 0 2 0
0 0 2 2

1 3 6 10 
*/
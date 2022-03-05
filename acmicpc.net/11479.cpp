#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
vector<ll> suffixArray(string s){
    int n=s.size();
    vector<ll> sa(n), rank(n+1), nextRank(n+1);
    for(ll i=0; i<n; ++i){
        sa[i]=i;
        rank[i]=s[i];
    }
    for(int d=1; d<n; d<<=1){
        auto cmp = [&](int i, int j) {
            return rank[i]<rank[j] || (rank[i]==rank[j] && rank[i+d]<rank[j+d]);
        };
        sort(sa.begin(), sa.end(), cmp);

        nextRank[sa[0]]=1;
        for(int i=1; i<n; ++i){
            nextRank[sa[i]] = nextRank[sa[i-1]] + cmp(sa[i-1], sa[i]);
        }
        rank = nextRank;
    }
    return sa;
}
vector<ll> buildLCP(string s){
    int n = s.size();
    vector<ll> sa = suffixArray(s), lcp(n), isa(n);
    for(ll i=0; i<n; ++i){
        isa[sa[i]]=i;
    }
    for(ll k=0, i=0; i<n; ++i){
        if(isa[i]) {
            for(ll j=sa[isa[i]-1]; s[i+k]==s[j+k]; ++k);
            lcp[isa[i]] = (k ? k-- : 0);
        }
    }
    return lcp;
}
int main(){
    string str; cin>>str;
    vector<ll> r = buildLCP(str);
    ll res=(1+str.size())*str.size()/2;
    for(auto it:r){
        res-=it;
    }
    cout << res << '\n';
}
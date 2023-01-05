#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N,G,B,D; cin>>N>>G>>B>>D;
    vector<pll> v;
    for(int i=0; i<N; ++i){
        ll x,y; cin>>x>>y;
        v.push_back({x,y});
    }
    v.push_back({D,0});
    sort(v.begin(), v.end());
    vector<ll> L(N+1, -1);
    vector<ll> st;
    for(int i=N; i>=0; --i){
        if(st.empty()){
            st.push_back(i);
        }
        else if(v[st.back()].second<=v[i].second){
            L[i]=st.back();
            st.push_back(i);
        }
        else{
            while(!st.empty() && v[st.back()].second>v[i].second){
                st.pop_back();
            }
            if(st.empty()){
                L[i]=-1;
            }
            else{
                L[i]=st.back();
            }
            st.push_back(i);
        }
        // cout << "L["<<i<<"]="<<L[i]<<'\n';
    }
    bool flag=true;
    ll res=0;
    ll lastest=0;
    for(int i=0; i<=N;){
        B-=v[i].first-lastest;
        lastest=v[i].first;
        if(B<0){
            cout << "-1\n";
            return 0;
        }
        if(L[i]==-1 || v[L[i]].first>v[i].first+G){
            ll need=G-B;
            res+=v[i].second*need;
            B=G;
            ++i;
        }
        else{
            ll need=max(0LL,v[L[i]].first-v[i].first-B);
            res+=v[i].second*need;
            B+=need;
            i=L[i];
        }
    }
    cout << res << '\n';
}

// [0] 2 40
// [1] 5 7
// [2] 9 15
// [3] 10 12
// [4] 17 0
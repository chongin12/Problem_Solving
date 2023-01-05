#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    vector<ll> v(N), L(N), R(N), st;
    for(ll i=0; i<N; ++i){
        cin>>v[i];
        while(!st.empty() && v[st.back()]>v[i]){
            R[st.back()]=i-st.back();
            st.pop_back();
        }
        st.push_back(i);
    }
    while(!st.empty()){
        R[st.back()]=N-st.back();
        st.pop_back();
    }
    for(ll i=N-1; i>=0; --i){
        while(!st.empty() && v[st.back()]>v[i]){
            L[st.back()]=st.back()-i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while(!st.empty()){
        L[st.back()]=st.back()+1;
        st.pop_back();
    }
    ll res=0;
    for(ll i=0; i<N; ++i){
        res=max((L[i]+R[i]-1)*v[i], res);
    }
    cout << res << '\n';
}
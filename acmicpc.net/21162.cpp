#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<ll P, ll M> struct Hasing {
    vector<ll> H,B;
    void build(const string &S){
        H.resize(S.size()+1);
        B.resize(S.size()+1);
        B[0] = 1;
        for(int i=1; i<=S.size(); ++i){
            H[i] = (H[i-1] * P + S[i-1]) % M;
        }
        for(int i=1; i<=S.size(); ++i){
            B[i] = B[i-1] * P % M;
        }
    }
    ll get(int s, int e){
        ll res = (H[e] - H[s-1] * B[e-s+1]) % M;
        return res >= 0 ? res : res + M;
    }
};
template<ll P, ll M> struct Hasing2 {
    vector<ll> H,B;
    void build(const vector<int> &S){
        H.resize(S.size()+1);
        B.resize(S.size()+1);
        B[0] = 1;
        for(int i=1; i<=S.size(); ++i){
            H[i] = (H[i-1] * P + S[i-1]) % M;
        }
        for(int i=1; i<=S.size(); ++i){
            B[i] = B[i-1] * P % M;
        }
    }
    ll get(int s, int e){
        s++, e++;
        ll res = (H[e] - H[s-1] * B[e-s+1]) % M;
        return res >= 0 ? res : res + M;
    }
};
Hasing2<524287, 998244353> H;
vector<int> str;
int K,N;
bool comp(int a, int b){
    int l=0, r=N-1;
    while(l<r){
        int mid=(l+r+1)/2;
        if(H.get(a, a+mid-1)!=H.get(b, b+mid-1)){
            r=mid-1;
        }
        else{
            l=mid;
        }
    }
    //처음으로 달라진 부분은 a+l, b+l.
    if(l==N-1){
        return false;
    }
    else{
        return str[a+l]<str[b+l];
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>N>>K;
    for(int i=0; i<N; ++i){
        int ch; cin>>ch;
        str.push_back(ch);
    }
    reverse(str.begin(), str.end());
    for(int i=0; i<N-1; ++i){
        str.push_back(str[i]);
    }
    H.build(str);
    vector<int> res(N-1);
    iota(res.begin(), res.end(), 1);
    stable_sort(res.begin(), res.end(), comp);
    for(int i=0; i<N; ++i){
        cout << str[i+res[K-1]] << " ";
    }
}
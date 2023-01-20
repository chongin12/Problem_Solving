// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(0); cin.tie(0);
//     int N; cin >> N;
//     vector<int> v;
//     for(int i=0; i<N; ++i){
//         int t; cin >> t;
//         if(i==0) v.push_back(t);
//         else {
//             auto it = lower_bound(v.begin(), v.end(), t) - v.begin();
//             //cout << "now : " << t << ", it : " << it << '\n';
//             //for(auto itt:v) cout << itt << " ";
//             //cout << '\n';
//             if(v.size()==it) v.push_back(t);           
//             else if(v[it]>t) v[it]=t;
//         }
//     }
//     cout << v.size() << '\n';
// }

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MN=1000001;
ll seg[MN*4+1];

ll Update(int idx, ll val, int n, int l, int r) {
    if(r<idx || idx<l) return seg[n];
    if(l==r) return seg[n] = val;
    int mid = (l+r)/2;
    return seg[n] = max(Update(idx, val, n*2, l, mid), Update(idx, val, n*2+1, mid+1, r));
}

ll Query(int L, int R, int n, int l, int r) {
    if (r<L || R<l) return 0;
    if(L<=l && r<=R) return seg[n];
    int mid = (l+r)/2;
    return max(Query(L, R, n*2, l, mid), Query(L, R, n*2+1, mid+1, r));
}
ll dp[MN]; // dp[i] : i로 끝나는 가장 긴 증가하는 부분 수열의 길이
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    ll res=0;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a;
        dp[a]=max(dp[a],Query(0,a-1,1,1,MN)+1);
        Update(a,dp[a],1,1,MN);
        res=max(res,dp[a]);
    }
    cout << res<<'\n';
}
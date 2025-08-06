#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, M, R; cin>>N>>M>>R;
    R*=2;
    vector<ll> A, B;

    for(ll i=0; i<N; ++i){
        ll a; cin>>a; A.push_back(a);
    }
    for(ll i=0; i<M; ++i){
        ll b; cin>>b; B.push_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    double res=0;
    for(ll i=0; i<N; ++i){
        for(ll j=i+1; j<N; ++j){
            ll l=A[j]-A[i];
            ll target=R/l;
            // cout << A[i] << " ~ " << A[j] << ", target = " << target << '\n';
            ll idx=upper_bound(B.begin(), B.end(), target) - B.begin();
            // cout << "B[idx]="<<B[idx] << '\n';
            idx=max(0LL,idx-1);
            if(B[idx]*l<=R){
                res=max(res,B[idx]*l/2.0);
            }
        }
    }
    if(res==0) cout << "-1\n";
    else {
        cout << fixed;
        cout.precision(1);
        cout << res << '\n';
    }
}
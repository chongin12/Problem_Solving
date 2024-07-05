#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v1, v2;
void init(){
    v1.clear();
    v2.clear();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        init();
        cout << "Case #" << t << endl;
        ll N; cin>>N;
        ll L; cin>>L;
        ll minimum=0;
        for(int i=0; i<N; ++i){
            ll a; cin>>a; v1.push_back(a);
        }
        for(int i=0; i<N; ++i){
            ll a; cin>>a; v2.push_back(a);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for(int i=0; i<N; ++i){
            minimum=max(minimum, abs(v1[i]-v2[i]));
        }
        // cout << "minimum : " << minimum << endl;
        ll res=minimum;
        for(int i=0; i<N; ++i){
            auto low=lower_bound(v2.begin(), v2.end(), v1[i]+L)-v2.begin();
            if(low>=0 && low<N && abs(v1[i]-v2[low])<=L) {
                res=max(res,abs(v1[i]-v2[low]));
            }
            low=lower_bound(v2.begin(), v2.end(), v1[i]-L)-v2.begin();
            if(low>=0 && low<N && abs(v1[i]-v2[low])<=L) {
                res=max(res,abs(v1[i]-v2[low]));
            }
        }
        if(res>L) cout << -1 << endl;
        else cout << res << endl;
    }
}
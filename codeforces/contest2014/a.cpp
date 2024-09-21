#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;
        int cur=0;
        int res=0;
        for(int i=0; i<n; ++i){
            int a; cin>>a;
            if(a<k) {
                if(a==0 && cur>0){
                    cur--;
                    res++;
                }
            }
            else {
                cur+=a;
            }
        }
        cout << res << '\n';
    }
}
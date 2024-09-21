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
        int r=0;
        for(int i=0; i<k%4; ++i){
            r+=(n+i)%2;
        }
        if(r%2) cout << "NO\n";
        else cout << "YES\n";
    }
}
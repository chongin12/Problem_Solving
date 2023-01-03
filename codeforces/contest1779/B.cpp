#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        if(n%2==0){
            cout << "YES\n";
            for(int i=0; i<n; ++i){
                if(i%2) cout << "1 ";
                else cout << "-1 ";
            }
            cout << '\n';
        }
        else{
            if(n==3) cout << "NO\n";
            else{
                cout << "YES\n";
                int k=(n-3)/2;
                for(int i=0; i<n; ++i){
                    if(i%2==0) cout << k << " ";
                    else cout << -k-1 << " ";
                }
                cout << '\n';
            }
        }
    }
}
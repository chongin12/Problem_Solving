#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int x,k; cin>>x>>k;
        if(x%k!=0){
            cout << "1\n"<<x << '\n';
        }
        else{
            cout << "2\n";
            for(int i=1; i<x; ++i){
                if(i%k!=0 && (x-i)%k!=0){
                    cout << i << " " << x-i << '\n';
                    break;
                }
            }
        }
    }
}
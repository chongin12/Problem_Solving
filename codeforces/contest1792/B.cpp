#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        ll a,b,c,d; cin>>a>>b>>c>>d;
        if(a==0) {
            cout << "1\n";
            continue;
        }
        ll temp = a+min(b,c)*2+min(max(b,c)-min(b,c)+d,a);
        if(temp<a+b+c+d) temp+=1;
        cout << temp << '\n';
    }
}
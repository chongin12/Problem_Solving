#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n, m, k; cin>>n>>m>>k;
        vector<int> v(m);
        for(int i=0; i<m; ++i) cin>>v[i];
        sort(v.begin(), v.end(), greater<int>());
        int D=n/k;
        if(n%k!=0) D+=1;
        if(D<v[0]){
            cout << "NO\n";
        }
        else{
            bool flag=true;
            for(int i=1; ;++i){
                if(v[i]!=v[i-1]) break;
                D=(n-i)/k;
                if((n-i)%k!=0) D+=1;
                if(D<v[i]){
                    flag=false;
                    break;
                }
            }
            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
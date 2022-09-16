#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> v;
    for(int i=0; i<2*n; ++i){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    int res=987654321;
    for(int i=0; i<n; ++i){
        res=min(res,v[i]+v[2*n-1-i]);
    }
    cout << res << '\n';
}
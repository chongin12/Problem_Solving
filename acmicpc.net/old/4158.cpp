#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        vector<int> v;
        int n,m; cin>>n>>m;
        if(n==0 && m==0) break;
        for(int i=0; i<n; ++i){
            int a; cin>>a;
            v.push_back(a);
        }
        int r=0;
        for(int i=0; i<m; ++i){
            int a; cin>>a;
            if(binary_search(v.begin(), v.end(), a)) ++r;
        }
        cout << r << '\n';
    }
}
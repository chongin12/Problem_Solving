#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<int> v;
    int res=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
        res=max(res,a);
        if(i>2){
            res=max(res,v[i-1]+min(v[i-2], v[i]));
        }
    }
    cout << res << '\n';
}
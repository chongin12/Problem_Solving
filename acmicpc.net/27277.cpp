#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    int res=v.back();
    v.pop_back();
    for(int i=0; i<(N-1)/2; ++i){
        res+=v[N-2-i]-v[i];
    }
    cout << res << '\n';
}
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int res = -1;
int main(){
    int N; cin>>N;
    v.push_back(0);
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(v.back()+a);
    }
    // cout << v.back() << '\n';
    int temp = v.back();
    int crossOffset = temp / 2;
    for(int i=0; i<N; ++i){
        int to_find;
        if(v[i] - crossOffset > 0){
            to_find = v[i]-crossOffset;
        } else {
            to_find = v[i]+crossOffset;
        }
        auto up = abs(*upper_bound(v.begin(), v.end(), to_find)-v[i]);
        int up_dist = min(up, v.back()-up);
        auto lo = abs(*lower_bound(v.begin(), v.end(), to_find)-v[i]);
        int lo_dist = min(lo, v.back()-lo);
        res=max({res,up_dist,lo_dist});
    }
    cout << res << '\n';
}
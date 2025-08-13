#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Node {
    ll w, h, i;
};
int main(){
    ll N; cin>>N;
    vector<Node> v;
    for(ll i=0; i<N; ++i){
        ll W, H; cin>>W>>H;
        v.push_back({W,H,i});
    }
    sort(v.begin(), v.end(), [](Node a, Node b){
        ll aa=a.w*a.w+a.h*a.h;
        ll bb=b.w*b.w+b.h*b.h;
        if(aa==bb) return a.i<b.i;
        return aa>bb;
    });
    for(auto it:v){
        cout << it.i+1 << '\n';
    }
}
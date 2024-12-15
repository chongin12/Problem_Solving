#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    int avail=0, res=0;
    for(auto it:v){
        int d = it.first, v = it.second;
        if(avail < v){
            res+=v-avail;
            avail=d;
        }
        else {
            avail = avail-v+d;
        }
    }
    cout << res << '\n';
}
#include <bits/stdc++.h>
using namespace std;
using psi=pair<string, int>;
int main(){
    int N, M, K; cin>>N>>M>>K;
    vector<psi> v;
    for(int i=0; i<N; ++i){
        string s; cin>>s;
        int a; cin>>a;
        v.push_back({s,a});
    }
    set<string> arr;
    for(int i=0; i<K; ++i){
        string s; cin>>s;
        arr.insert(s);
    }
    int r1=0, r2=0;
    vector<psi> vv;
    for(auto it:v){
        if(arr.find(it.first) == arr.end()){
            vv.push_back(it);
        }
        else {
            r1+=it.second;
            r2+=it.second;
        }
    }
    sort(vv.begin(), vv.end(), [](psi a, psi b){
        return a.second < b.second;
    });
    for(int i=0; i<M-K; ++i){
        r1+=vv[i].second;
        r2+=vv[vv.size()-i-1].second;
    }
    cout << r1 << " " << r2 << '\n';
}
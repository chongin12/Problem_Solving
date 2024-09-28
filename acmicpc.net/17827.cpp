#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, V; cin>>N>>M>>V; V--;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    while(M--){
        int K; cin>>K;
        if(K<N) cout << v[K] << '\n';
        else {
            cout << v[(K-V)%(N-V)+V] << '\n';
        }
    }
}
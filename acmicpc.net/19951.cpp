#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int dacc[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    for(int i=0; i<M; ++i){
        int a, b, k; cin>>a>>b>>k;
        dacc[a-1]+=k;
        dacc[b]-=k;
    }
    int acc=0;
    for(int i=0; i<N; ++i){
        acc+=dacc[i];
        cout << v[i]+acc << " ";
    }
    cout << '\n';
}
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    int k; cin>>k;
    k=N/k;
    for(int i=0; i<N; i+=k){
        sort(v.begin()+i, v.begin()+i+k);
    }
    for(auto it:v){
        cout << it << " ";
    }
    cout << '\n';
}
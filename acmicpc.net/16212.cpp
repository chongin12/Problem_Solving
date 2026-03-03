#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v;
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(auto it:v){
        cout << it << " ";
    }
    cout << '\n';
}
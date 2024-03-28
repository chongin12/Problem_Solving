#include <bits/stdc++.h>
using namespace std;
vector<double> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        double a; cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    cout << fixed;
    cout.precision(3);
    for(int i=0; i<7; ++i){
        cout << v[i] << '\n';
    }
}
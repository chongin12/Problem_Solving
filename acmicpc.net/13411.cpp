#include <bits/stdc++.h>
using namespace std;
vector<pair<double, int>> arr;
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        double x, y, v; cin>>x>>y>>v;
        arr.push_back({sqrt(x*x+y*y)/v, i});
    }
    sort(arr.begin(), arr.end());
    for(auto it:arr){
        cout << it.second+1 << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
    int N; cin>>N;
    vector<pii> v;
    for(int i=0; i<N; ++i){
        int t,s; cin>>t>>s;
        v.push_back({t,s});
    }
    sort(v.begin(), v.end(), [](pii a, pii b){
        return a.second > b.second;
    });
    int k=v[0].second;
    for(auto it:v){
        if(it.second < k) {
            k=it.second - it.first;
        }
        else {
            k-=it.first;
        }
    }
    if(k<0){
        cout << "-1\n";
    }
    else{
        cout << k << '\n';
    }
}
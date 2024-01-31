#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a, b; cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), [](pii a, pii b){
        return a.second>b.second;
    });
    int k=v[0].second;
    for(auto it:v){
        if(it.second<k){
            k=it.second-it.first;
        }
        else{
            k=k-it.first;
        }
    }
    cout << k << '\n';
}
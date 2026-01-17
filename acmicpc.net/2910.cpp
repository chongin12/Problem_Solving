#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
    int N, C; cin>>N>>C;
    map<int, int> m;
    map<int, int> k;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        m[a]++;
        if(m[a]==1){
            k[a]=i;
        }
    }
    vector<pii> v;
    for(auto it:m){
        v.push_back(it);
    }
    sort(v.begin(), v.end(), [&](pii a, pii b){
        if(a.second==b.second){
            return k[a.first]<k[b.first];
        }
        return a.second>b.second;
    });
    for(auto it:v){
        for(int i=0; i<it.second; ++i){
            cout << it.first << " ";
        }
    }
    cout << '\n';
}
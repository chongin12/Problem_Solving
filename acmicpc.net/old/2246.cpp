#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    vector<pair<int,int> > v;
    for(int i=0; i<N; ++i){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    int res=0;
    for(int i=0; i<N; ++i){
        bool flag=true;
        for(int j=0; j<N; ++j){
            if(i==j) continue;
            if(v[i].first > v[j].first && v[i].second >= v[j].second) flag=false;
            if(v[i].second > v[j].second && v[i].first >= v[j].first) flag=false;
        }
        if(flag) res++;
    }
    cout << res << '\n';
}
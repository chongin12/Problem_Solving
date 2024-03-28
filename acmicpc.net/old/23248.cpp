#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int INF=987654321;
int main(){
    int m, n, k; cin>>m>>n>>k;
    set<int> s;
    vector<pii> v;
    for(int i=0; i<k; ++i){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    s.insert(0);
    s.insert(INF);
    int res=0;
    for(int i=0; i<v.size(); ++i){
        auto it=s.lower_bound(v[i].second+1);
        int r=*(--it);
        if(r==0){
            res++;
            s.insert(v[i].second);
        }
        else{
            s.erase(it);
            s.insert(v[i].second);
        }
    }
    cout << res << '\n';
}
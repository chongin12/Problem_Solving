#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int,int>;
vector<pii> v;
vector<pii> res;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; ++i){
        int k; cin >> k;
        v.push_back({k, i});
    }
    sort(v.begin(), v.end());
    int c=0;
    res.push_back({v[0].second, c});
    for(int i=1; i<N; ++i){
        if(v[i].first == v[i-1].first) res.push_back({v[i].second, c});
        else res.push_back({v[i].second, ++c});
    }
    sort(res.begin(), res.end());
    for(int i=0; i<N; ++i){
        cout << res[i].second << " ";
    }
    cout << '\n';
}
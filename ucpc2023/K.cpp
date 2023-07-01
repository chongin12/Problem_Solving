#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

vector<ll> v;
ll N, T;
bool f(ll x){ // 최대 겹치는 세미나 수가 x개 이하로 가능?
    // cout << "x : " << x << '\n';
    vector<pii> ranges;
    pii first = {v[0]-T+1, v[0]};
    if(first.first<=0) {
        first.second+=-first.first+1;
        first.first=1;
    }
    ranges.push_back(first);
    ll availIdx=0; // 겹치는 구간은 여기부터
    for(ll i=1; i<v.size(); ++i){
        pii temp = {v[i]-T+1, v[i]};
        if(temp.first<=0) {
            temp.second+=-temp.first+1;
            temp.first=1;
        }
        while(availIdx<i){
            if(ranges[availIdx].second < temp.first) availIdx++;
            else break;
        }
        // availIdx부터 i까지 겹침.
        while(i-availIdx+1>x){
            temp.second += ranges[availIdx].second-temp.first+1;
            temp.first += ranges[availIdx].second-temp.first+1;
            availIdx++;
        }
        if(!(temp.first <= v[i] && v[i] <= temp.second)){
            return false;
        }
        ranges.push_back(temp);
        
        // cout << "i : " << i<< '\n';
        // for(auto it:ranges){
        //     cout << "(" << it.first << ", " << it.second << ")\n";
        // }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>T;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    ll lo=0, hi=200000;
    while(lo<hi-1){
        ll mid = (lo+hi)/2;
        if(f(mid)) hi=mid;
        else lo=mid;
    }
    cout << hi << '\n';
}
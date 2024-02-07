#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<int> v;
vector<pii> v2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, K; cin>>N>>M>>K;
    int temp=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    int prev;
    cin>>prev; prev--;
    for(int i=1; i<=K; ++i){
        int a;
        if(i==K) a=N+1;
        else cin>>a;
        a--;
        temp=0;
        for(int j=prev; j<a; ++j){
            temp+=v[j];
        }
        v2.push_back({temp, prev});
        prev=a;
    }
    sort(v2.begin(), v2.end(), [](pii a, pii b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    });
    vector<int> res;
    for(int i=0; i<M; ++i){
        res.push_back(v2[i].second+1);
    }
    sort(res.begin(), res.end());
    for(auto it:res){
        cout << it << '\n';
    }
}
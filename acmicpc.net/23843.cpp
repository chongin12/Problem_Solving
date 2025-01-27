#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M; cin>>N>>M;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<int>());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<M; ++i){
        pq.push(0);
    }
    int res=0;
    for(auto it:v){
        auto a = pq.top(); pq.pop();
        a+=it;
        pq.push(a);
        res=max(res,a);
    }
    cout << res << '\n';
}
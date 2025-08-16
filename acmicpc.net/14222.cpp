#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, K; cin>>N>>K;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        pq.push(a);
    }
    for(int i=1; i<=N; ++i){
        auto cur = pq.top(); pq.pop();
        if(cur>i) {
            cout << "0\n";
            return 0;
        }
        if(cur==i) continue;
        pq.push(cur+K);
        --i;
    }
    if(pq.empty()) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
    
}
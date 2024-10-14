#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, K; cin>>N>>K;
    queue<pair<int,int>> q; // 숫자, 사람
    for(int i=0; i<N; ++i){
        for(int j=0; j<K; ++j){
            int a; cin>>a;
            q.push({a,i});
        }
    }
    while(q.size() != 1){
        auto cur = q.front(); q.pop();
        for(int i=0; i<cur.first-1; ++i){
            q.push(q.front());
            q.pop();
        }
    }

    cout << q.front().second+1 << " " << q.front().first << '\n';
}
#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
    queue<pii> q;
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        q.push({a, i+1});
    }
    vector<int> res;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        res.push_back(cur.second);
        if(q.empty()) break;
        if(cur.first<0) {
            cur.first = q.size()-abs(cur.first)%q.size()+1;
        }
        // cout << cur.first-1 << " moved\n";
        for(int i=0; i<cur.first-1; ++i){
            auto temp = q.front(); q.pop();
            q.push(temp);
        }
    }
    for(auto it:res){
        cout << it << " ";
    }
    cout << '\n';
}
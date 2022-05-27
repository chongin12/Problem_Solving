#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin>>N>>K;
    priority_queue<pair<int,int> > pq;
    for(int i=0; i<K; ++i) {
        int a; cin>>a;
        pq.push({a,i+1});
    }
    vector<int> res;
    int prev=-1;
    while(!pq.empty()){
        pair<int,int> cur = pq.top(); pq.pop();
        if(cur.second==prev){
            if(pq.empty()){
                res.clear();
                break;
            }
            pair<int,int> cur2 = pq.top(); pq.pop();
            res.push_back(cur2.second);
            prev=cur2.second;
            if(cur2.first!=1) pq.push({cur2.first-1, cur2.second});
            pq.push(cur);
        }
        else{
            res.push_back(cur.second);
            prev=cur.second;
            if(cur.first!=1) pq.push({cur.first-1, cur.second});
        }
    }
    if(res.size()!=N) {
        cout << "-1\n";
    }
    else {
        for(auto it:res) cout << it << ' ';
        cout << '\n';
    }
}
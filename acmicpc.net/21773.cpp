#include <bits/stdc++.h>
using namespace std;
struct Process {
    int priority;
    int id;
    int t;

};

struct Compare {
    bool operator()(Process a, Process b){
        if(a.priority == b.priority){
            return a.id > b.id;
        }
        return a.priority < b.priority;
    }
};
priority_queue<Process, vector<Process>, Compare> pq;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, n; cin>>T>>n;
    for(int i=0; i<n; ++i){
        int a, b, c; cin>>a>>b>>c;
        pq.push({c,a,b});
    }
    for(int i=1; i<=T; ++i){
        auto cur = pq.top(); pq.pop();
        cout << cur.id << '\n';
        if(cur.t!=1){
            cur.t-=1;
            cur.priority-=1;
            pq.push(cur);
        }
    }
}
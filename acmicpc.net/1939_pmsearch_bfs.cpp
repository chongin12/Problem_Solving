#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int INF=1987654321;
vector<pii> G[10001];
int visited[10001];
int U,V;
void init() {
    for(int i=0; i<10001; ++i) visited[i]=0;
}
int f(int x){
    init();
    queue<int> q;
    q.push(U);
    visited[U]=1;
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(auto it:G[cur]){
            if(it.second >= x && !visited[it.first]){
                if(it.first == V) return 1;
                visited[it.first]=1;
                q.push(it.first);
            }
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int A,B,C; cin>>A>>B>>C;
        G[A].push_back({B,C});
        G[B].push_back({A,C});
    }
    cin>>U>>V;
    int lo=1, hi=1000000001;
    while(lo<hi-1){
        int mid=(lo+hi)/2;
        if(f(mid)) {lo=mid;}
        else {hi=mid;}
    }
    cout << lo << '\n';
}
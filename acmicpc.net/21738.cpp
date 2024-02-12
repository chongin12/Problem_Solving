#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int,int>;
vector<int> G[328001];
int visited[328001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, S, P; cin>>N>>S>>P;
    for(int i=0; i<N-1; ++i){
        int A, B; cin>>A>>B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    queue<pii> q;
    q.push({P, 0});
    visited[P]=1;
    int res=0;
    int cnt=0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.x<=S) {
            res+=cur.y;
            cnt++;
            if(cnt==2) break;
        }
        else{
            for(auto it:G[cur.x]){
                if(visited[it]) continue;
                q.push({it, cur.y+1});
                visited[it]=1;
            }
        }
    }
    cout << N-res-1 << '\n';
}
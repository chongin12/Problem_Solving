#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int visited[100011];
int main(){
    int N, S, D, F, B, K; cin>>N>>S>>D>>F>>B>>K;
    for(int i=0; i<K; ++i){
        int a; cin>>a;
        visited[a]=1;
    }
    queue<pii> q;
    q.push({S,0});
    visited[S]=1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.first==D){
            cout << cur.second << '\n';
            return 0;
        }
        if(cur.first+F<=N && !visited[cur.first+F]){
            q.push({cur.first+F, cur.second+1});
            visited[cur.first+F]=1;
        }
        if(cur.first-B>0 && !visited[cur.first-B]){
            q.push({cur.first-B, cur.second+1});
            visited[cur.first-B]=1;
        }
    }
    cout << "BUG FOUND\n";
}
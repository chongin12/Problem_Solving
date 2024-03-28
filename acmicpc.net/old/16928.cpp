#include <iostream>
#include <queue>
using namespace std;
int arr[101];
queue<pair<int, int> > q;
int visit[101];
int bfs() {
    q.push({1, 0});
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        //cout << cur.first << ", " << cur.second << '\n';
        if(cur.first == 100) return cur.second;
        for(int i=1; i<=6; ++i){
            if(cur.first+i>100) break;
            if(visit[cur.first+i]) continue;
            visit[cur.first+i] = 1;
            q.push({arr[cur.first+i], cur.second+1});
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i=0; i<101; ++i){
        arr[i] = i;
    }
    for(int i=0; i<N+M; ++i){
        int a, b; cin >> a >> b;
        arr[a]=b;
    }
    cout << bfs() << '\n';
}
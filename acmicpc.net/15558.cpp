#include <bits/stdc++.h>
using namespace std;
int visited[2][200002];
int arr[2][200002];
const int INF = 987654321;
struct Node {
    int x, y, k;
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin>>N>>K;
    for(int i=0; i<2; ++i){
        string str; cin>>str;
        for(int j=1; j<=N; ++j){
            arr[i][j]=str[j-1]=='0'?0:1;
        }
    }
    queue<Node> q;
    q.push({0,1,1});
    visited[0][1]=1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        // cout << "cur : " << (cur.x ? "오른쪽" : "왼쪽") << ", " << cur.y << " | " << cur.k << '\n';
        if(cur.y+K>N || cur.y>N){
            cout << "1\n";
            return 0;
        }
        if(arr[cur.x][cur.y+1]==1 && !visited[cur.x][cur.y+1]){
            q.push({cur.x, cur.y+1, cur.k+1});
            visited[cur.x][cur.y+1]=1;
        }

        if(arr[!cur.x][cur.y+K]==1 && !visited[!cur.x][cur.y+K]){
            q.push({!cur.x, cur.y+K, cur.k+1});
            visited[!cur.x][cur.y+K]=1;
        }
        if(cur.y>cur.k+1 && arr[cur.x][cur.y-1]==1 && !visited[cur.x][cur.y-1]){
            q.push({cur.x, cur.y-1, cur.k+1});
            visited[cur.x][cur.y-1]=1;
        }
    }
    cout << "0\n";
}

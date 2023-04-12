#include <bits/stdc++.h>
using namespace std;
int F, S, G, U, D;
int dp[1000001];
int visited[1000001];
const int INF = 987654321;
int f(int x){
    int res=INF;
    queue<pair<int,int> > q;
    q.push({x,0});
    visited[x]=1;
    while(!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        int curx = cur.first;
        int curcnt = cur.second;
        if(curx==G){
            res=min(res, curcnt);
            continue;
        }
        if(curx+U<=F && !visited[curx+U]){
            visited[curx+U]=1;
            q.push({curx+U, curcnt+1});
        }
        if(curx-D>0 && !visited[curx-D]){
            visited[curx-D]=1;
            q.push({curx-D, curcnt+1});
        }

    }
    return res;
}
int main(){
    cin>>F>>S>>G>>U>>D;
    int res=f(S);
    if(res==INF) cout << "use the stairs\n";
    else cout << res << '\n';
}
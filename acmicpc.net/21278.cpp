#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<int> G[101];
int main(){
    int N, M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int a, b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int res=987654321;
    pii p(0,0);

    for(int i=1; i<=N; ++i){
        for(int j=i+1; j<=N; ++j){
            queue<pii> q;
            vector<int> visited(101,0);
            int temp=0;
            q.push({i,0});
            q.push({j,0});
            visited[i]=1;
            visited[j]=1;
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                temp += cur.second*2;
                for(auto nxt:G[cur.first]){
                    if(!visited[nxt]){
                        q.push({nxt, cur.second+1});
                        visited[nxt]=1;
                    }
                }
            }
            if(temp < res){
                p = {i,j};
                res=temp;
            }
        }
    }
    cout << p.first << " " << p.second << " " << res << '\n';
}
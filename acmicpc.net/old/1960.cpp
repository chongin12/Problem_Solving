#include <bits/stdc++.h>
using namespace std;
const int SHIFT=501;
vector<int> G[1011];
int c[1011][1011], f[1011][1011];
int S=1006, T=1007;
int MaxFlow(){
    int ret=0;
    while(1){
        queue<int> q; q.push(S);
        vector<int> p(1011, -1); p[S]=S;
        while(!q.empty() && p[T]==-1){
            int cur = q.front(); q.pop();
            for(auto nxt:G[cur]){
                if(c[cur][nxt]-f[cur][nxt]>0 && p[nxt] == -1){
                    q.push(nxt);
                    p[nxt]=cur;
                }
            }
        }
        if(p[T]!=-1){
            int flow = 1987654321;
            for(int i=T; i!=S; i=p[i]){
                flow = min(flow, c[p[i]][i]-f[p[i]][i]);
            }
            for(int i=T; i!=S; i=p[i]){
                f[p[i]][i]+=flow;
                f[i][p[i]]-=flow;
            }
            ret+=flow;
        }
        else break;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int sum=0, sum2=0;
    for(int i=1; i<=n; ++i){
        int a; cin>>a;
        c[S][i]=a;
        G[S].push_back(i);
        G[i].push_back(S);
        for(int j=1; j<=n; ++j){
            c[i][j+SHIFT]=1;
            G[i].push_back(j+SHIFT);
            G[j+SHIFT].push_back(i);
        }
        sum+=a;
    }
    for(int i=1; i<=n; ++i){
        int a; cin>>a;
        c[i+SHIFT][T]=a;
        G[i+SHIFT].push_back(T);
        G[T].push_back(i+SHIFT);
        sum2+=a;
    }
    int res = MaxFlow();
    if(sum==sum2 && res==sum){
        cout << "1\n";
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(f[i][j+SHIFT]==1){
                    cout << "1";
                }
                else{
                    cout << "0";
                }
            }
            cout << '\n';
        }
    }
    else{
        cout << "-1\n";
    }
}
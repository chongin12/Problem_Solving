#include <bits/stdc++.h>
using namespace std;
const int MN = 10000;
int k, N;
vector<int> G[2*MN+1];
vector<int> RG[2*MN+1];
int visited[2*MN+1];

vector<int> st;

vector<vector<int> > scc;

int res[2*MN+1];

void DFS(int n){
    visited[n] = true;
    for(int i=0; i<G[n].size(); ++i){
        if(!visited[G[n][i]]){
            DFS(G[n][i]);
        }
    }
    st.push_back(n);
}
void DFS2(int n){
    visited[n] = true;
    for(int i=0; i<RG[n].size(); ++i){
        if(!visited[RG[n][i]]){
            DFS2(RG[n][i]);
        }
    }
    scc.back().push_back(n);
}
int ToNot(int a){
    if(a<=k) a+=MN;
    else a-=MN;
    return a;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> k >> N;
    for(int i=0; i<N; ++i){
        int a, b, c; char q, w, e; 
        cin >> a >> q >> b >> w >> c >> e;
        if(q=='B') a=ToNot(a);
        if(w=='B') b=ToNot(b);
        if(e=='B') c=ToNot(c);
        G[ToNot(a)].push_back(b);
        G[ToNot(b)].push_back(a);
        RG[b].push_back(ToNot(a));
        RG[a].push_back(ToNot(b));

        G[ToNot(b)].push_back(c);
        G[ToNot(c)].push_back(b);
        RG[c].push_back(ToNot(b));
        RG[b].push_back(ToNot(c));

        G[ToNot(a)].push_back(c);
        G[ToNot(c)].push_back(a);
        RG[c].push_back(ToNot(a));
        RG[a].push_back(ToNot(c));
    }
    for(int i=1; i<=2*MN; ++i){
        if(!visited[i]) DFS(i);
    }
    reverse(st.begin(), st.end());
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<st.size(); ++i){
        int n = st[i];
        if(visited[n]) continue;
        scc.push_back(vector<int>()); // 새로운 scc 생성
        DFS2(n); // 역방향 그래프에서 DFS를 돌리면서 만나는 모든 정점을 새로운 SCC에 담아줌.
    }
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<scc.size(); ++i){
        for(int j=0; j<scc[i].size(); ++j){
            int n=scc[i][j];
            if(visited[ToNot(n)]==true) {
                cout << -1 << '\n';
                return 0;
                
            }
            visited[n]=true;
        }
        for(int j=0; j<scc[i].size(); ++j){
            visited[scc[i][j]] = false;
        }
    }
    memset(visited, 0, sizeof(visited));
    
    for(int i=0; i<scc.size(); ++i){
        for(int j=0; j<scc[i].size(); ++j){
            int n=scc[i][j];
            if(visited[n]) continue;
            visited[n]=true;
            visited[ToNot(n)]=true;
            res[n]=0;
            res[ToNot(n)]=1;
        }
    }
    string resstr="";
    for(int i=1; i<=k; ++i){
        if(res[i]) resstr+="R";
        else resstr+="B";
    }
    cout << resstr << '\n';
}
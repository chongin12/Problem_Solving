#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N;
int c[200][200]; // c[a][b] : a->b의 간선의 용량
int f[200][200]; // f[a][b] : a->b의 간선의 유량
vector<int> G[200];

int MaxFlow(int src, int snk) { // src에서 snk로 가는 최대 유량을 리턴한다.
    int ret = 0;
    while(1){
        queue<int> q; q.push(src);
        vector<int> p(200, -1); p[src]=src;// parents
        while(!q.empty() && p[snk] == -1){
            int n = q.front(); q.pop();
            for(int i=0; i<G[n].size(); ++i){
                int next = G[n][i];
                if(c[n][next] - f[n][next] >0 && p[next] == -1){
                    q.push(next);
                    p[next] = n;
                }
            }
        }
        if(p[snk]==-1) break;
        int flow = 1234567890;//INF
        for(int i=snk; i!=src; i=p[i]){
            flow = min(flow, c[p[i]][i] - f[p[i]][i]);
        }
        for(int i=snk; i!=src; i=p[i]){
            f[p[i]][i] += flow;
            f[i][p[i]] -= flow;
        }
        ret += flow;
    }
    return ret;
}

int main(){
    cin >> N;
    for(int i=0; i<N; ++i){
        char a, b;
        int x;
        cin >> a >> b >> x;
        G[a].push_back(b);
        G[b].push_back(a);
        c[a][b] += x;
        c[b][a] += x;
    }
    cout << MaxFlow((int)'A', (int)'Z') << '\n';
}
#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int N,M,K;

struct node {
    int v, ch;
    node(int v, int ch):v(v),ch(ch){}
};
struct edge {
    int v, kk, cnt, ch;
    edge(int v, int kk, int cnt, int ch):v(v),kk(kk),cnt(cnt),ch(ch){}
};
vector<node> G[100102];
void init(){
    for(int i=0; i<100102; ++i){
        G[i].clear();
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        init();
        cout << "Case #"<<t<<endl;
        cin>>N>>M>>K;
        if(K==-1) K=5000;
        for(int i=1; i<=M; ++i){
            int u,v; char ch; cin>>u>>v>>ch;
            int temp;
            if(ch=='A') temp=0;
            else if(ch=='B') temp=1;
            else temp=2;
            G[u].push_back(node(v,temp));
        }
        bool flag=false;
        int res=0;
        for(int i=1; i<=N; ++i){
            queue<edge> q;
            for(int j=0; j<G[i].size(); ++j){
                q.push(edge(G[i][j].v,0,1,G[i][j].ch));
            }
            
            while(!q.empty()){
                edge cur=q.front(); q.pop();
                res=max(res,cur.cnt);
                if(cur.cnt>=100) {
                    flag=true;
                    break;
                }
                if(cur.kk>=500){
                    flag=true;
                    break;
                }
                for(auto it:G[cur.v]){
                    if((cur.ch+1)%3==it.ch){
                        q.push(edge(it.v,cur.kk,cur.cnt+1,it.ch));
                    }
                    else{
                        if(cur.kk==K) continue;
                        q.push(edge(it.v,cur.kk+1,cur.cnt,it.ch));
                    }
                }
            }
            if(flag) break;
        }
        if(flag) cout << "-1"<<endl;
        else cout << res << endl;
    }

}
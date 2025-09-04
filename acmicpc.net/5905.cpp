#include <bits/stdc++.h>
using namespace std;
int t=0;
int visited[1001][15*20+1];
struct Trie {
    Trie * go[3];
    Trie * fail;
    bool chk;
    int cnt;
    int nodeIdx;

    Trie() {
        fill(go, go+3, nullptr);
        fail = nullptr;
        chk = false;
        cnt=0;
        nodeIdx=++t;
    }

    ~Trie() {
        for(int i=0; i<3; ++i){
            if(go[i]) delete go[i];
        }
    }

    void insert(const char * key) {
        if(*key == '\0'){
            chk=true;
            cnt++;
            return;
        }
        int idx = *key - 'A';
        if(!go[idx]){
            go[idx]=new Trie();
        }
        go[idx]->insert(key+1);
    }
};
int dp[1001][15*20+1];
Trie * root = new Trie();
int main(){
    int N, K; cin>>N>>K;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        root->insert(str.c_str());
    }

    queue<Trie *> q;
    root->fail = root;
    q.push(root);
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int w=0; w<3; ++w){
            if(!cur->go[w]) continue;
            if(cur==root){
                cur->go[w]->fail = root;
            }
            else {
                auto dest = cur->fail;
                while(dest!=root && !dest->go[w]){
                    dest=dest->fail;
                }
                if(dest->go[w]) dest=dest->go[w];
                // cout << cur->go[w]->nodeIdx << " failed -> " << dest->nodeIdx << '\n';
                cur->go[w]->fail = dest;
            }
            if(cur->go[w]->fail->chk) {
                cur->go[w]->chk = true;
                cur->go[w]->cnt += cur->go[w]->fail->cnt;
            }
            q.push(cur->go[w]);
        }
    }

    queue<pair<Trie *, int>> dpQ;

    int res=0;
    dpQ.push({root, 0});
    while(!dpQ.empty()){
        auto curPair = dpQ.front(); dpQ.pop();
        auto cur = curPair.first;
        auto i = curPair.second;
        // cout << "cur = " << cur->nodeIdx << ", dp[" << i << "][" << cur->nodeIdx << "]=" << dp[i][cur->nodeIdx] << '\n';
        if(i==K){
            res=max(res,dp[i][cur->nodeIdx]);
            continue;
        }
        for(int idx=0; idx<3; ++idx){
            auto nxt = cur;
            while(nxt!=root && !nxt->go[idx]){
                nxt=nxt->fail;
            }
            if(nxt->go[idx]) nxt=nxt->go[idx];

            dp[i+1][nxt->nodeIdx] = max(dp[i+1][nxt->nodeIdx], dp[i][cur->nodeIdx]+nxt->cnt);

            if(!visited[i+1][nxt->nodeIdx]){
                dpQ.push({nxt, i+1});
                visited[i+1][nxt->nodeIdx]=1;
            }
        }
    }
    cout << res << '\n';
}
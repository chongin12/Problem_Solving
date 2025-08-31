#include <bits/stdc++.h>
using namespace std;
struct Trie {
    Trie * go[4];
    Trie * fail; // 실패 시 돌아갈 곳. ababc에서 abc를 찾아야 할 때 abab에서 ab로 되돌아가야 한다.
    bool chk;

    Trie() {
        fill(go, go+4, nullptr);
        chk=false;
    }
    ~Trie() {
        for(int i=0; i<4; ++i){
            if(go[i]) delete go[i];
        }
    }
    void insert(const char* key) {
        if(*key=='\0'){
            chk=true;
            return;
        }
        int next;
        if(*key == 'A') next=0;
        else if(*key == 'C') next=1;
        else if(*key == 'G') next=2;
        else if(*key == 'T') next=3;

        if(!go[next]){
            go[next] = new Trie();
        }
        go[next]->insert(key+1);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    Trie * root;
    while(T--){
        int N, M; cin>>N>>M;
        string s, marker; cin>>s>>marker;
        set<string> markerSet;
        string temp="";
        for(int i=0; i<M; ++i){
            for(int j=1; i+j<=M; ++j){
                temp="";
                for(int w=0; w<i; ++w){
                    temp+=marker[w];
                }
                for(int w=i+j-1; w>=i; --w){
                    temp+=marker[w];
                }
                for(int w=i+j; w<M; ++w){
                    temp+=marker[w];
                }
                markerSet.insert(temp);
            }
        }

        root = new Trie();
        for(auto it:markerSet){
            root->insert(it.c_str());
        }

        queue<Trie*> q;
        root->fail = root;
        q.push(root);
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int i=0; i<4; ++i){
                auto nxt = cur->go[i];
                if(!nxt) continue;

                if(cur == root) nxt->fail = root;
                else {
                    auto dest = cur->fail;
                    // cur의 fail에서 go[i]가 있는 가장 가까운 fail을 찾아간다.
                    while(dest != root && !dest->go[i]){
                        dest = dest->fail;
                    }
                    // go[i]로 한번 이동한 것이 cur의 fail이다.
                    if(dest->go[i]) dest=dest->go[i];
                    nxt->fail = dest;
                }
                // fail로 이동한 곳이 chk가 되어있으면 nxt 노드도 chk 미리 해주기
                if(nxt->fail->chk) nxt->chk = true;
                q.push(nxt);
            }
        }
        // 여기까지 Trie 구성과 fail함수 구성 끝.

        int res=0;
        Trie * current = root;
        for(int i=0; i<N; ++i){
            int next;
            if(s[i] == 'A') next=0;
            else if(s[i] == 'C') next=1;
            else if(s[i] == 'G') next=2;
            else if(s[i] == 'T') next=3;

            // 불가능하면 fail 함수 계속 적용하기
            while(current!=root && !current->go[next]){
                current = current->fail;
            }
            if(current->go[next]){
                current = current->go[next];
            }
            if(current->chk){
                res++;
            }
        }
        cout << res << '\n';
        delete root;
    }
}
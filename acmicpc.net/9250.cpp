#include <bits/stdc++.h>
using namespace std;
struct Trie {
    Trie* go[26];
    Trie* fail;
    bool output;
    Trie() {
        for(int i=0; i<26; ++i) go[i]=NULL;
        output = false;
    }
    void insert(const char* key){
        if(*key=='\0'){
            output=true;
            return;
        }
        int next=*key-'a';
        if(go[next]==NULL){
            go[next]=new Trie;
        }
        go[next]->insert(key+1);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    Trie* root = new Trie;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        root->insert(str.c_str());
    }
    //fail 만들기
    queue<Trie*> q;
    root->fail = root;
    q.push(root);
    while(!q.empty()){
        Trie* cur=q.front(); q.pop();

        for(int i=0; i<26; ++i){
            Trie* nxt = cur->go[i];
            if(nxt==NULL) continue;

            if(cur==root) {
                nxt->fail = root;
            }
            else{
                Trie* dst = cur->fail;
                while(dst != root && dst->go[i] == NULL){
                    dst = dst->fail;
                }
                if(dst->go[i] != NULL) dst = dst->go[i];
                nxt->fail=dst;
            }
            if(nxt->fail->output) nxt->output = true;
            q.push(nxt);
        }
    }
    int Q; cin>>Q;
    while(Q--){
        string str; cin>>str;
        Trie* cur=root;
        bool flag=false;
        for(int i=0; i<str.size(); ++i){
            int nxt=str[i]-'a';
            while(cur!=root && cur->go[nxt]==NULL){
                cur=cur->fail;
            }
            if(cur->go[nxt] != NULL) cur=cur->go[nxt];
            if(cur->output){
                flag=true;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
#include <bits/stdc++.h>
using namespace std;
map<char, int> charMap;
int cnt=0;
struct Trie {
    Trie * go[90];
    Trie * fail;
    bool chk;
    Trie() {
        fill(go, go+90, nullptr);
        fail = nullptr;
        chk = false;
    }

    ~Trie() {
        for(int i=0; i<90; ++i){
            if(go[i]) delete go[i];
        }
    }

    void insert(const char * key) {
        if(*key=='\0'){
            chk=true;
            return;
        }
        int idx = charMap[*key];
        if(!go[idx]) go[idx]=new Trie();
        go[idx]->insert(key+1);
    }
};
int main(){
    while(true) {
        int N, M; cin>>N>>M; cin.ignore();
        if(N==0 && M==0) break;
        Trie * root = new Trie();
        for(int i=0; i<N; ++i){
            string str; getline(cin, str);
            for(auto it:str){
                if(charMap.find(it)==charMap.end()) charMap[it]=cnt++;
            }
            root->insert(str.c_str());
        }

        root->fail = root;
        queue<Trie *> q;
        q.push(root);
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int i=0; i<90; ++i){
                if(!cur->go[i]) continue;
                if(cur == root){
                    cur->go[i]->fail = root;
                }
                else {
                    auto dest = cur->fail;
                    while(dest!=root && !dest->go[i]){
                        dest=dest->fail;
                    }
                    if(dest->go[i]) {
                        dest=dest->go[i];
                    }
                    cur->go[i]->fail=dest;
                }
                if(cur->go[i]->fail->chk){
                    cur->go[i]->chk = true;
                }
                q.push(cur->go[i]);
            }
        }

        int res=0;

        for(int i=0; i<M; ++i){
            string str; getline(cin, str);
            Trie * current = root;
            for(int j=0; j<str.size(); ++j){
                auto it = str[j];
                if(charMap.find(it)!=charMap.end()){
                    int idx = charMap[it];
                    while(current!=root && !current->go[idx]){
                        current = current->fail;
                    }
                    if(current->go[idx]){
                        current = current->go[idx];
                    }
                    if(current->chk){
                        current=root;
                        res++;
                    }
                }
                else {
                    current = root;
                }
            }
        }
        delete root;
        cout << res << '\n';
    }
}
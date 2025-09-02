#include <bits/stdc++.h>
using namespace std;
struct Trie {
    Trie * go[26];
    Trie * fail;
    bool chk;
    int length;
    Trie() {
        fill(go, go+26, nullptr);
        fail = nullptr;
        chk=false;
        length=0;
    }
    ~Trie() {
        for(int i=0; i<26; ++i){
            if(go[i]) delete go[i];
        }
    }
    void insert(const char * key, int len) {
        if(*key=='\0'){
            chk=true;
            length = len;
            return;
        }
        int idx = *key - 'a';
        if(!go[idx]) {
            go[idx] = new Trie();
        }
        go[idx]->insert(key+1, len);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    string s; cin>>s;
    int M; cin>>M;
    vector<string> inputs;
    for(int i=0; i<M; ++i){
        string str; cin>>str;
        inputs.push_back(str);
    }
    vector<pair<int,int>> v;
    while(!inputs.empty()){
        Trie * root = new Trie();
        for(int j=0; j<100; ++j){
            if(inputs.empty()) break;
            auto str = inputs.back(); inputs.pop_back();
            root->insert(str.c_str(), str.length());
        }
        root->fail = root;
        queue<Trie *> q;
        q.push(root);
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int i=0; i<26; ++i){
                if(!cur->go[i]) continue;
                if(cur==root) cur->go[i]->fail = root;
                else {
                    auto dest = cur->fail;
                    while(dest != root && !dest->go[i]) {
                        dest = dest->fail;
                    }
                    if(dest->go[i]){
                        dest = dest->go[i];
                    }
                    cur->go[i]->fail = dest;
                }
                if(cur->go[i]->fail->chk) {
                    cur->go[i]->chk = true;
                    cur->go[i]->length = max(cur->go[i]->length, cur->go[i]->fail->length);
                }
                q.push(cur->go[i]);
            }
        }
        Trie * current = root;
        for(int i=0; i<N; ++i){
            int idx = s[i] - 'a';
            while(current != root && !current->go[idx]){
                current = current->fail;
            }
            if(current->go[idx]){
                current = current->go[idx];
            }
            if(current->chk){
                v.push_back({max(0,i-current->length+1), i+1}); // [left,right)구간을 만들 수 있음.
            }
        }
        delete root;
    }
    
    vector<int> arr(N+10, 0);
    for(auto it:v){
        arr[it.first] += 1;
        arr[it.second] -= 1;
    }
    int res=0;
    int temp=0;
    for(int i=0; i<N; ++i){
        temp+=arr[i];
        if(!temp) res++;
    }
    cout << res << '\n';
}
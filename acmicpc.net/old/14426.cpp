#include <bits/stdc++.h>
using namespace std;
struct Trie {
    bool isTerminal;
    Trie *nxt[26];
    Trie():isTerminal(false){
        for(int i=0; i<26; ++i) nxt[i]=NULL;
    }
    void insert(const char *ch){
        if(*ch=='\0'){
            isTerminal=true;
            return;
        }
        if(nxt[*ch-'a']==NULL){
            nxt[*ch-'a']=new Trie();
        }
        nxt[*ch-'a']->insert(ch+1);
    }
    bool findPrefix(const char *ch){
        if(*ch=='\0'){
            return true;
        }
        if(nxt[*ch-'a']==NULL){
            return false;
        }
        return nxt[*ch-'a']->findPrefix(ch+1);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M; cin>>N>>M;
    Trie *root = new Trie();
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        root->insert(str.c_str());
    }
    int res=0;
    for(int i=0; i<M; ++i){
        string str; cin>>str;
        if(root->findPrefix(str.c_str())) res++;
    }
    cout << res << '\n';
}
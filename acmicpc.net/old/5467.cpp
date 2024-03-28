#include <bits/stdc++.h>
using namespace std;
vector<char> res;
struct Trie {
    bool isTerminal;
    int maxDepth;
    Trie *nxt[26];
    Trie():isTerminal(false),maxDepth(0){
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
    int dfs1(int depth) { // return : maxDepth
        for(int i=0; i<26; ++i){
            if(nxt[i]!=NULL) maxDepth = max(maxDepth, nxt[i]->dfs1(depth+1));
        }
        if(maxDepth == 0) maxDepth=depth;
        return maxDepth;
    }
    void dfs2(bool isLast) {
        if(isTerminal) res.push_back('P');
        vector<int> v; // 뒤에서부터 nxt[v[i]] 탐색. 맨 앞은 maxDepth가 가장 높은 위치
        for(int i=0; i<26; ++i){
            if(nxt[i]!=NULL){
                v.push_back(i);
                if(nxt[v.back()]->maxDepth > nxt[v[0]]->maxDepth){
                    swap(v[0], v.back());
                }
            }
        }
        for(int i=v.size()-1; i>=0; --i){
            res.push_back('a'+v[i]);
            if(i==0 && isLast){
                nxt[v[0]]->dfs2(isLast);
            }
            else{
                nxt[v[i]]->dfs2(0);
                res.push_back('-');
            }
        }

    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin>>N;
    Trie *root = new Trie();
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        root->insert(str.c_str());
    }
    root->dfs1(0);
    root->dfs2(1);
    cout << res.size() << '\n';
    for(auto it:res){
        cout << it << '\n';
    }
}
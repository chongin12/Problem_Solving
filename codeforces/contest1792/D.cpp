#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Trie {
    bool isTerminal;
    Trie *nxt[10];
    Trie():isTerminal(false){
        for(int i=0; i<10; ++i) nxt[i]=NULL;
    }
    void insert(const char *ch){
        if(*ch=='\0'){
            isTerminal=true;
            return;
        }
        if(nxt[*ch-'0']==NULL){
            nxt[*ch-'0']=new Trie();
        }
        nxt[*ch-'0']->insert(ch+1);
    }
    int findPrefix(const char *ch, int now){
        if(*ch=='\0'){
            return now;
        }
        if(nxt[*ch-'0']==NULL){
            return now;
        }
        return nxt[*ch-'0']->findPrefix(ch+1, now+1);
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n,m; cin>>n>>m;
        vector<string> v2;
        Trie *root = new Trie();
        for(int i=0; i<n; ++i){
            string temp;
            int arr[11]={0,};
            string str="";
            for(int j=0; j<m; ++j){
                int a; cin>>a; --a; temp.push_back(a+'0');
                arr[a]=j;
            }
            for(int j=0; j<m; ++j){
                str+=(char)(arr[j]+'0');
            }
            root->insert(str.c_str());
            v2.push_back(temp);
        }
        for(int i=0; i<n; ++i){
            cout << root->findPrefix(v2[i].c_str(), 0) << " ";
        }
        cout << '\n';
    }
}
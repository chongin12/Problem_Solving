#include <bits/stdc++.h>
using namespace std;
int idxOf(char ch){
    if(ch=='.') return 0; // 0
    if(ch>='0' && ch<='9') return 1+ch-'0'; // 1~10
    if(ch>='A' && ch<='Z') return 11+ch-'A'; // 11 ~ 36
    if(ch>='a' && ch<='z') return 37+ch-'a'; // 37 ~ 62
    return -1;
}
int res=0;
struct Trie{
    Trie *arr[65];
    bool isEnd;
    bool isRed;
    Trie(){
        isEnd=false;
        isRed=false;
        for(int i=0; i<65; ++i) arr[i]=NULL;
    }
    void insert(const char *c){
        if(*c=='\0'){
            isEnd=true;
            return;
        }
        if(arr[idxOf(*c)]==NULL){
            arr[idxOf(*c)]=new Trie();
        }
        arr[idxOf(*c)]->insert(c+1);
    }
    void removeAll(){
        for(int i=0; i<65; ++i){
            if(arr[i]!=NULL) {
                arr[i]->removeAll();
                free(arr[i]);
            }
        }
    }
    void moveRed(const char *c){
        if(isRed==true){
            isRed=false;
            res--;
            for(int i=0; i<65; ++i){
                if(arr[i]!=NULL){
                    if(arr[i]->isRed==false){
                        arr[i]->isRed=true;
                        res++;
                    }
                }
            }
        }
        if(*c=='\0') return;
        if(isEnd==true) {
            res++;
            isEnd=false;
        }
        if(arr[idxOf(*c)]!=NULL){
            arr[idxOf(*c)]->moveRed(c+1);
        }
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        res=0;
        Trie *root = new Trie();
        int N1, N2; cin>>N1;
        for(int i=0; i<N1; ++i){
            string str; cin>>str;
            root->insert(str.c_str());
        }
        root->isRed=true;
        res++;
        cin>>N2;
        for(int i=0; i<N2; ++i){
            string str; cin>>str;
            root->moveRed(str.c_str());
        }
        cout << res << '\n';
        root->removeAll();
        free(root);
    }
}
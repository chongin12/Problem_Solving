#include <bits/stdc++.h>
using namespace std;
pair<string, bool> strDivideBy2(string str){
    string res="";
    bool spare=false;
    for(int i=0; i<str.size(); ++i){
        int k=0;
        if(spare) k=10;
        k+=str[i]-'0';
        if(k%2) spare=true;
        else spare=false;
        k/=2;
        res+='0'+k;
    }
    string ret="";
    int i=-1;
    while(res[++i]=='0');
    for(; i<res.size(); ++i){
        ret+=res[i];
    }
    return {ret,spare};
}
struct Trie{
    Trie *left;
    Trie *right;
    bool isEndPoint;
    Trie(){
        left=NULL;
        right=NULL;
        isEndPoint=false;
    }
    void insert(const char *c){
        if(*c=='\0'){
            isEndPoint=true;
            return;
        }
        if(*c=='0'){
            if(left==NULL) left=new Trie();
            left->insert(c+1);
        }
        else{
            if(right==NULL) right = new Trie();
            right->insert(c+1);
        }
    }
};
int dfs(Trie *x, bool isCount){
    int ret=0;
    if(isCount==false && (x->isEndPoint==true || (x->left!=NULL && x->right!=NULL))){
        isCount=true;
    }
    if(isCount) ret=1;
    if(x->left!=NULL){
        ret+=dfs(x->left, isCount);
    }
    if(x->right!=NULL){
        ret+=dfs(x->right, isCount);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    Trie *root = new Trie();
    for(int i=0; i<N; ++i){
        vector<char> v;
        string str; cin>>str;
        string dir="";
        pair<string, bool> temp=strDivideBy2(str);
        while(temp.first!=""){
            if(temp.second){
                dir+='1';
            }
            else{
                dir+='0';
            }
            temp=strDivideBy2(temp.first);
        }
        reverse(dir.begin(), dir.end());
        root->insert(dir.c_str());
    }
    cout << dfs(root, false) << '\n';
}
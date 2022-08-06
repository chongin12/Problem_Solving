#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Trie {
    Trie *next0;
    Trie *next1;
    int next0Size, next1Size;
    Trie():next0(NULL),next1(NULL),next0Size(0),next1Size(0){}
    void insert(const char *ch){
        if(*ch=='\0') return;
        else if(*ch=='1') {
            if(next1==NULL) next1 = new Trie();
            next1Size++;
            next1->insert(ch+1);
        }
        else{
            if(next0==NULL) next0 = new Trie();
            next0Size++;
            next0->insert(ch+1);
        }
    }
};
ll sum[101001]={0,};
ll res;
void init() {
    for(int i=0; i<101001; ++i){
        sum[i]=0;
    }
    res=0;
}
void resUpdate(string str){
    ll ret=0;
    for(ll i=str.size()-1, k=1; i>=0; --i, k*=2){
        if(str[i]=='1') ret+=k;
    }
    res=max(res,ret);
}
void f(Trie * t1, Trie * t2, string str, int cnt) {
    if(cnt==32) {
        resUpdate(str);
        return;
    }
    bool flag=true;
    if(t1->next0Size && t2->next1Size){
        flag=false;
        f(t1->next0, t2->next1, str+"1", cnt+1);
    }
    if(t1->next1Size && t2->next0Size){
        flag=false;
        f(t1->next1, t2->next0, str+"1", cnt+1);
    }
    if(flag && t1->next0Size && t2->next0Size){
        f(t1->next0, t2->next0, str+"0", cnt+1);
    }
    if(flag && t1->next1Size && t2->next1Size){
        f(t1->next1, t2->next1, str+"0", cnt+1);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        init();
        Trie *root = new Trie();
        for(int i=1; i<=N; ++i){
            ll a; cin>>a;
            sum[i]=sum[i-1]^a;
        }
        for(int i=0; i<=N; ++i){
            string str="";
            for(int j=0; j<=31; ++j){
                if(sum[i]%2==0){
                    str='0'+str;
                }
                else{
                    str='1'+str;
                }
                sum[i]/=2;
            }
            root->insert(str.c_str());
        }
        Trie *t1=root, *t2=root;
        f(t1,t2,"",0);
        // cout << "res : " << res << '\n';
        
        cout << res << '\n';
    }
}
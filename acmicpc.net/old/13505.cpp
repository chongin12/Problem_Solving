#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
struct Trie{
    int level;
    Trie *next0;
    int next0Size;
    Trie *next1;
    int next1Size;
    Trie(int level):level(level){
        next0=NULL;
        next1=NULL;
        next0Size=0;
        next1Size=0;
    }
    void insert(const char *n){
        if(*n!='0' && *n!='1') return;
        if(*n=='0'){
            next0Size++;
            if(next0==NULL) next0=new Trie(level+1);
            next0->insert(n+1);
        }
        else if(*n=='1'){
            next1Size++;
            if(next1==NULL) next1=new Trie(level+1);
            next1->insert(n+1);
        }
    }
};
void fbit(char *arr, ll x){
    for(int i=31; i>=0; --i){
        if(x%2==0) arr[i]='0';
        else arr[i]='1';
        x/=2;
    }
}
ll res=0;
void result(string s){
    ll cnt=0, k=1;
    for(int i=31; i>=0; --i){
        cnt+=(s[i]-'0')*k;
        k*=2;
    }
    res=max(res,cnt);
}
void f(Trie *now1, Trie *now2, string str){
    if(now1->level==31) {
        result(str);
        return;
    }
    bool flag=true;
    if(now1->next0Size>0 && now2->next1Size>0){
        flag=false;
        string nxt=str;
        nxt+="1";
        f(now1->next0, now2->next1, nxt);
    }
    if(now1->next1Size>0 && now2->next0Size>0){
        flag=false;
        string nxt=str;
        nxt+="1";
        f(now1->next1, now2->next0, nxt);
    }
    if(flag && now1->next0Size>0 && now2->next0Size){
        string nxt=str;
        nxt+="0";
        f(now1->next0, now2->next0, nxt);
    }
    if(flag && now1->next1Size>0 && now2->next1Size){
        string nxt=str;
        nxt+="0";
        f(now1->next1, now2->next1, nxt);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    Trie *root = new Trie(-1);
    for(int i=0; i<N; ++i){
        ll a; cin>>a;
        char arr[32]={};
        fbit(arr, a);
        root->insert(arr);
    }
    f(root, root, "");
    cout << res << '\n';
}
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
        // cout << "level : " << level << ", insert : " << *n << '\n';
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
    void remove(const char *n){
        if(*n!='0' && *n!='1') return;
        if(*n=='0'){
            if(next0Size==0) return;
            next0->remove(n+1);
            next0Size--;
            if(next0Size==0) {
                free(next0);
                next0=NULL;
            }
        }
        else if(*n=='1'){
            if(next1Size==0) return;
            next1->remove(n+1);
            next1Size--;
            if(next1Size==0) {
                free(next1);
                next1=NULL;
            }
        }
    }
    void f(char *res, const char *x){
        if(next0Size==0 && next1Size==0) return;
        if(level==31) return;
        if(x[level+1]=='0' && next1Size!=0){
            res[level+1]='1';
            next1->f(res, x);
        }
        else if(x[level+1]=='1' && next0Size!=0){
            res[level+1]='1';
            next0->f(res, x);
        }
        else if(x[level+1]=='0'){
            res[level+1]='0';
            next0->f(res, x);
        }
        else{
            res[level+1]='0';
            next1->f(res, x);
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
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int M; cin>>M;
    Trie *root = new Trie(-1);
    char temp[32]={};
    for(int i=0; i<32; ++i) temp[i]='0';
    root->insert(temp);
    while(M--){
        ll a,x; cin>>a>>x;
        if(a==1){
            char arr[32]={};
            fbit(arr, x);
            root->insert(arr);
        }
        else if(a==2){
            char arr[32]={0,};
            fbit(arr, x);
            root->remove(arr);
        }
        else{
            char arr[32]={};
            fbit(arr, x);
            char res[32]={};
            root->f(res, arr);
            ll cnt=0, k=1;
            for(int i=31; i>=0; --i){
                cnt+=(res[i]-'0')*k;
                k*=2;
            }
            cout << cnt << '\n';
        }
    }
}
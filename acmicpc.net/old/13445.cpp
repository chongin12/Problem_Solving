#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Trie {
    Trie *next0;
    Trie *next1;
    ll next0Size, next1Size;
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
void ff(Trie * t1, Trie * t2, int lv, bool isVisited1, bool isTarget, const char * target){
    if(lv==19) {
        if(isTarget){
            if(*target=='1'){
                if(isVisited1){
                    res+=t1->next0Size*t2->next0Size+t1->next1Size*t2->next1Size;
                }
                else{
                    if(t1->next0Size>=2){
                        res+=(t1->next0Size)*(t1->next0Size-1)/2;
                    }
                    if(t1->next1Size>=2){
                        res+=(t1->next1Size)*(t1->next1Size-1)/2;
                    }
                }
            }
        }
        else{
            if(isVisited1){
                res+=t1->next0Size*t2->next1Size;
                res+=t1->next1Size*t2->next0Size;
                res+=t1->next0Size*t2->next0Size;
                res+=t1->next1Size*t2->next1Size;
            }
            else{
                res+=t1->next0Size*t2->next1Size;
                if(t1->next0Size>=2){
                    res+=(t1->next0Size)*(t1->next0Size-1)/2;
                }
                if(t1->next1Size>=2){
                    res+=(t1->next1Size)*(t1->next1Size-1)/2;
                }
            }
        }
        return;
    }
    if(isTarget){
        if(*target=='1'){
            if(t1->next0Size && t2->next1Size){
                ff(t1->next0, t2->next1, lv+1, true, true, target+1);
            }
            if(t1->next1Size && t2->next0Size){
                ff(t1->next1, t2->next0, lv+1, true, true, target+1);
            }
            if(isVisited1){
                if(t1->next0Size && t2->next0Size){
                    ff(t1->next0, t2->next0, lv+1, true, false, target+1);
                }
                if(t1->next1Size && t2->next1Size){
                    ff(t1->next1, t2->next1, lv+1, true, false, target+1);
                }
            }
            else{
                if(t1->next0Size>=2){
                    ff(t1->next0, t2->next0, lv+1, false, false, target+1);
                }
                if(t1->next1Size>=2){
                    ff(t1->next1, t2->next1, lv+1, false, false, target+1);
                }
            }
        }
        else{
            if(isVisited1){
                if(t1->next0Size && t2->next0Size){
                    ff(t1->next0, t2->next0, lv+1, true, true, target+1);
                }
                if(t1->next1Size && t2->next1Size){
                    ff(t1->next1, t2->next1, lv+1, true, true, target+1);
                }
            }
            else{
                if(t1->next0Size>=2){
                    ff(t1->next0, t2->next0, lv+1, false, true, target+1);
                }
                if(t1->next1Size>=2){
                    ff(t1->next1, t2->next1, lv+1, false, true, target+1);
                }
            }
        }
    }
    else{
        if(t1->next0Size && t2->next1Size){
            ff(t1->next0, t2->next1, lv+1, true, false, target+1);
        }
        if(t1->next1Size && t2->next0Size){
            ff(t1->next1, t2->next0, lv+1, true, false, target+1);
        }
        if(isVisited1){
            if(t1->next0Size && t2->next0Size){
                ff(t1->next0, t2->next0, lv+1, true, false, target+1);
            }
            if(t1->next1Size && t2->next1Size){
                ff(t1->next1, t2->next1, lv+1, true, false, target+1);
            }
        }
        else{
            if(t1->next0Size>=2){
                ff(t1->next0, t2->next0, lv+1, false, false, target+1);
            }
            if(t1->next1Size>=2){
                ff(t1->next1, t2->next1, lv+1, false, false, target+1);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin>>N>>K;
    Trie *root = new Trie();
    for(int i=1; i<=N; ++i){
        ll a; cin>>a;
        sum[i]=sum[i-1]^a;
    }
    for(int i=0; i<=N; ++i){
        string str="";
        for(int j=0; j<=19; ++j){
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
    string kStr="";
    for(int j=0; j<=19; ++j){
        if(K%2==0) kStr='0'+kStr;
        else kStr='1'+kStr;
        K/=2;
    }
    Trie *t1=root, *t2=root;
    ff(t1,t2,0,false,true,kStr.c_str());
    
    cout << res << '\n';
}
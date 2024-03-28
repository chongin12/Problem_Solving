#include <bits/stdc++.h>
using namespace std;
int S[1000001];
int F[1000001];
int tp,tk,now;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        cin>>S[N-i-1];
    }
    int k=N-1,p=1;
    for(int i=1, j=0; i<N; ++i){
        while(j>0 && S[j]!=S[i]) j=F[j-1];
        if(S[j]==S[i]) F[i]=++j;
        
    }
    for(int i=N-1; i>=0; --i){
        tp = i+1-F[i];
        tk = N-i-1;
        if(!(tk+tp<k+p || (tk+tp==k+p && tp<p))) continue;
        now=i-tp;
        bool pass=true;
        while(now+1>tp){
            if(now+1-F[now]!=tp){
                pass=false;
                break;
            }
            now=now-tp;
        }
        if(pass){
            k=tk;
            p=tp;
        }
    }
    cout << k << " " << p << '\n';
}
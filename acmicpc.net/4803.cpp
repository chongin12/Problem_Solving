#include <bits/stdc++.h>
using namespace std;
int par[501], chk[501];
vector<int> chkTemp;
void init(){
    for(int i=0; i<501; ++i){
        par[i]=i;
        chk[i]=0;
    }
    chkTemp.clear();
}
int Find(int X){
    if(X==par[X]) return X;
    return par[X]=Find(par[X]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a==b){
        chkTemp.push_back(a);
    }
    else {
        par[a]=b;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int T=1;;++T){
        init();
        int N, M; cin>>N>>M;
        if(N==0) break;
        for(int i=0; i<M; ++i){
            int a, b; cin>>a>>b;
            // 유니온파인드로 합치기. 같은 그룹 이었다면 체크해두기.
            Union(a,b);
        }
        for(auto it:chkTemp) {
            chk[Find(it)] = 1;
        }
        int res=0;
        for(int i=1; i<=N; ++i){
            if(!chk[Find(i)]) {
                chk[Find(i)]=1;
                res++;
            }
        }
        cout << "Case " << T << ": ";
        if(res==0) cout << "No trees.\n";
        else if(res==1) cout << "There is one tree.\n";
        else cout << "A forest of " << res << " trees.\n";
    }
}
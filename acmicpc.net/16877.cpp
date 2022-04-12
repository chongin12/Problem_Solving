#include <bits/stdc++.h>
using namespace std;
const int MN=3e6+1;
int mex[MN];
int fibo[32];
int visited[32];
void init(){
    for(int i=0; i<32; ++i){ visited[i]=0; }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    fibo[0]=1;
    fibo[1]=2;
    for(int i=2; i<32; ++i){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    int N; cin>>N;
    for(int i=1; i<MN; ++i){
        init();
        for(int j=0; j<32 && i-fibo[j]>=0; ++j){
            visited[mex[i-fibo[j]]]=1;
        }
        for(int j=0; j<32; ++j){
            if(!visited[j]){
                mex[i]=j;
                break;
            }
        }
    }
    // for(int i=0; i<20; ++i){
    //     cout << "mex["<<i<<"]="<<mex[i]<<'\n';
    // }
    int res=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a; res^=mex[a];
    }
    if(res==0) cout << "cubelover\n";
    else cout << "koosaga\n";
}
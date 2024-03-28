#include <bits/stdc++.h>
using namespace std;
int cache[1011];
int main(){
    int N; cin>>N;
    cache[0]=0;
    cache[1]=0;
    cache[2]=1;
    cache[3]=1;
    for(int i=4; i<=N; ++i){
        int chk[16]={};
        for(int j=i-2; j>=0; --j){
            int k=i-2-j;
            chk[cache[j]^cache[k]]=1;
        }
        for(int j=0; j<16; ++j){
            if(!chk[j]) {
                cache[i]=j;
                break;
            }
        }
    }
    if(cache[N]) cout << "1\n";
    else cout << "2\n";
}
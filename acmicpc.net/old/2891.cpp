#include <bits/stdc++.h>
using namespace std;
int isBroken[101];
int has[101];
int main(){
    int N, S, R; cin>>N>>S>>R;
    for(int i=0; i<S; ++i){
        int a; cin>>a; isBroken[a]=1;
    }
    for(int i=0; i<R; ++i){
        int a; cin>>a; has[a]=1;
        if(isBroken[a]){
            isBroken[a]=0;
            has[a]=0;
            S--;
        }
    }
    int cnt=0;
    for(int i=1; i<=N; ++i){
        if(isBroken[i]){
            if(i!=1 && has[i-1]){
                has[i-1]=0;
                isBroken[i]=0;
                cnt++;
                continue;
            }
            if(has[i]){
                has[i]=0;
                isBroken[i]=0;
                cnt++;
                continue;
            }
            if(i!=N && has[i+1]){
                has[i+1]=0;
                isBroken[i]=0;
                cnt++;
                continue;
            }
        }
    }
    cout << S-cnt << '\n';
}
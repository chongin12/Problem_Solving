#include <bits/stdc++.h>
using namespace std;
int isErased[1001];
int main(){
    int N, K; cin>>N>>K;
    for(int p=2; p<=N; ++p){
        if(isErased[p]) continue;
        if(K==1){
            cout << p << '\n';
            return 0;
        }
        for(int i=p; i<=N; i+=p){
            if(isErased[i]) continue;
            if(K==1){
                cout << i << '\n';
                return 0;
            } else {
                K--;
                isErased[i]=1;
            }
        }
    }
}
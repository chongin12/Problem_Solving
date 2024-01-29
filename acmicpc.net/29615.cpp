#include <bits/stdc++.h>
using namespace std;
int rnk[1001];
int main(){
    int N, M; cin>>N>>M;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        rnk[a]=i;
    }
    int res=0;
    for(int i=0; i<M; ++i){
        int a; cin>>a;
        if(rnk[a]>=M) res++;
    }
    cout << res << '\n';
}
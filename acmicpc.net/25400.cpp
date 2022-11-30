#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    int res=1;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(a==res) res++;
    }
    cout << N-(res-1)<<'\n';
}
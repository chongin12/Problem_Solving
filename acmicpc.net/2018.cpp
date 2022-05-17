#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    int res=0;
    int l=1, r=1;
    int now=1;
    while(1){
        if(now==N) {
            res++;
            now+=++r;
        }
        else if(now<N){
            now+=++r;
        }
        else{
            now-=l++;
        }
        if(l>N || r>N) break;
    }
    cout << res << '\n';
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    int prev=1987654321;
    int res=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(prev<a){
            res=max(res,a-prev);
        }
        prev=min(prev,a);
    }
    cout << res << '\n';
}
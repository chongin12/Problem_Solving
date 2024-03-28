#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M; cin>>N>>M;
    int q; cin>>q;
    int l=1, r=M;
    int res=0;
    for(int i=0; i<q; ++i){
        int a; cin>>a;
        if(a<l){
            int d=l-a;
            res+=d;
            l-=d;
            r-=d;
        }
        else if(r<a){
            int d=a-r;
            res+=d;
            l+=d;
            r+=d;
        }
    }
    cout << res << '\n';
}
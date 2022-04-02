#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MAX=1000000;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    int cnt=0;
    while(T--){
        cout << "Case #"<<++cnt<<": ";
        int a=INF,b=INF,c=INF,d=INF;
        for(int i=0; i<3; ++i){
            int q,w,e,r; cin>>q>>w>>e>>r;
            a=min(a,q);
            b=min(w,b);
            c=min(c,e);
            d=min(d,r);
        }
        int tot=MAX;
        if(a>=tot){
            a=tot;
            tot=0;
        }
        else{
            tot-=a;
        }
        if(b>=tot){
            b=tot;
            tot=0;
        }
        else{
            tot-=b;
        }
        if(c>=tot){
            c=tot;
            tot=0;
        }
        else{
            tot-=c;
        }
        if(d>=tot){
            d=tot;
            tot=0;
        }
        else{
            tot-=d;
        }
        if(tot!=0) {
            cout << "IMPOSSIBLE\n";
        }
        else{
            cout << a << " " << b << " " << c << " " << d << '\n';
        }
    }
}
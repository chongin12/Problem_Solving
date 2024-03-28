#include <bits/stdc++.h>
using namespace std;
int main(){
    int w,h; cin>>w>>h;
    int p,q; cin>>p>>q;
    int t; cin>>t;
    int a=(p+t)%(w*2);
    if(a>w) a=w*2-a;
    int b=(q+t)%(h*2);
    if(b>h) b=h*2-b;
    cout << a << ' ' << b << '\n';
}
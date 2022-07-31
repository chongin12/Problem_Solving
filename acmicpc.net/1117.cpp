#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll W,H,f,c,x1,y1,x2,y2; cin>>W>>H>>f>>c>>x1>>y1>>x2>>y2;
    ll a=(min(f,x2)-x1)*(y2-y1);
    if(a<0) a=0;
    ll b=(min(W-f,x2)-x1)*(y2-y1);
    if(b<0) b=0;
    c++;
    cout << W*H-(a+b)*c << '\n';
}
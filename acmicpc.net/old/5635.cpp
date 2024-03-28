#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    pair<string, int> Min("",20999999),Max("",10000000);
    while(n--){
        string str; int a,b,c; cin>>str>>a>>b>>c;
        pair<string, int> p(str,10000*c+100*b+a);
        if(p.y<Min.y) Min=p;
        if(p.y>Max.y) Max=p;
    }
    cout << Max.x << '\n' << Min.x << '\n';
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int A,B; cin>>A>>B;
    set<int> s;
    for(int i=0; i<A; ++i){
        int a; cin>>a;
        s.insert(a);
    }
    int r=0;
    for(int i=0; i<B; ++i){
        int b; cin>>b;
        if(s.find(b)!=s.end()) r++;
    }
    cout << A+B-r*2 << '\n';
}
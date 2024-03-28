#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    vector<int> a(6),b(6);
    for(int i=0; i<6; ++i){
        cin>>a[i];
    }
    for(int i=0; i<6; ++i){
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res=0;
    for(int i=0; i<6; ++i){
        for(int j=0; j<6; ++j){
            if(a[i]>b[j]) res++;
        }
    }
    if(res==0) cout << 0 << '\n';
    else cout << res/gcd(res,36) << "/" << 36/gcd(res,36) << '\n';
}
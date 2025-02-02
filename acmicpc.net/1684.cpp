#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int main(){
    int N; cin>>N;
    vector<int> v;
    int res=-1;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        for(auto it:v){
            if(res==-1) res=abs(it-a);
            else res=gcd(res,abs(it-a));
        }
        v.push_back(a);
    }
    cout << res << '\n';
}
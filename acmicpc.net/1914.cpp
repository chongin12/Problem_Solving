#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string a="1";
void calc(){
    string newA = "";
    int t=1;
    for(int i=a.length()-1; i>=0; --i){
        int k = a[i]-'0';
        k*=2;
        k+=t;
        t=k/10; k%=10;
        newA.push_back((char)(k+'0'));
    }
    if(t) newA+=t+'0';
    reverse(newA.begin(), newA.end());
    a = newA;
}
string dp[101];
void f(ll a, ll b, ll x){ // a -> b로 x개 옮기기
    if(x==1){
        cout << a << " " << b << '\n';
        return;
    }
    ll c = 6-a-b;
    f(a, c, x-1);
    f(a, b, 1);
    f(c, b, x-1);
}
int main(){
    ll N; cin>>N;
    dp[1]=a;
    for(ll i=2; i<=N; ++i){
        calc();
        dp[i]=a;
    }
    cout << dp[N] << '\n';
    if(N<=20){
        f(1, 3, N);
    }
}
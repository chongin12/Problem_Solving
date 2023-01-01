#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int f(int n){
    int sum=0;
    for(int i=1; i<n; ++i){
        if(n%i==0) sum+=i;
    }
    if(sum<n) return 0;
    else if(sum>n) return 1;
    else return 2;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int a; cin>>a;
        bool flag=true;
        if(f(a)==1){
            for(int i=1; i<a; ++i){
                if(a%i==0 && f(i)==1) flag=false;
            }
        }
        else{
            flag=false;
        }
        if(flag) cout << "Good Bye\n";
        else cout << "BOJ 2022\n";
    }
}
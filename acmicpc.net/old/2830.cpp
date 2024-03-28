#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll arr[2][100000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<ll> v;
    for(int i=0; i<N; ++i){
        ll a; cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int m=0;
    ll temp=v.back();
    while(temp!=0){
        m++;
        temp/=2;
    }
    for(int i=0; i<N; ++i){
        ll a=v[i];
        for(int j=0; j<m; ++j){
            if(a%2) arr[1][j]+=1;
            else arr[0][j]+=1;
            a/=2;
        }
    }
    ll res=0;
    for(int i=0; i<v.size()-1; ++i){
        ll k=1;
        ll num=v[i];
        for(int j=0; j<m; ++j, k*=2){
            if(num%2==1){
                arr[1][j]--;
                res+=arr[0][j]*k;
            }
            else{
                arr[0][j]--;
                res+=arr[1][j]*k;
            }
            num/=2;
        }
    }
    cout << res << '\n';
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll s[100001];
int arr[2][100001];
int main(){
    int N; cin>>N;
    ll MN=-1;
    for(int i=1; i<=N; ++i){
        ll a; cin>>a;
        s[i]=s[i-1]^a;
        MN=max(MN,s[i]);
    }
    ll k=0; // 비트 개수
    while(MN>0){
        k++;
        MN/=2;
    }
    for(int i=0; i<=N; ++i){
        ll temp=s[i];
        for(int j=0; j<k; ++j){
            if(temp%2) arr[1][j]++;
            else arr[0][j]++;
            temp/=2;
        }
    }
    ll res=0;
    for(int i=0; i<=N; ++i){
        ll mul=1;
        for(int j=0; j<k; ++j){
            if(s[i]%2) {
                arr[1][j]--;
                res+=arr[0][j]*mul;
            }
            else {
                arr[0][j]--;
                res+=arr[1][j]*mul;
            }
            s[i]/=2;
            mul*=2;
        }
    }
    cout << res << '\n';
}
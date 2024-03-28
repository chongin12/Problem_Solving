#include <bits/stdc++.h>
using namespace std;
int arr[1000002];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, L; cin>>N>>L;
    for(int i=1; i<=N; ++i){
        int a; cin>>a; arr[i]=arr[i-1]+a;
    }
    int res=0;
    for(int i=1; i<=N; ++i){
        int a=arr[i], b=0;
        if(i-L>0) b=arr[i-L];
        if(a-b>=129 && a-b<=138) res++;
    }
    cout << res << '\n';
}
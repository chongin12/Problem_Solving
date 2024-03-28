#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int arr[1000001];
int main(){
    int N; cin>>N;
    arr[0]=0;
    arr[1]=1;
    for(int i=2; i<=N; ++i){
        arr[i]=(arr[i-2]+arr[i-1])%MOD;
    }
    cout << arr[N] << '\n';
}
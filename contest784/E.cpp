#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll arr[200101];
ll N, M;
bool f(int x){ // x 간격으로 일해서 할당량을 다 채울 수 있다면 true
    ll dp[200101]={}; // dp[i] : i까지 고려할 때, x 간격 이상으로 하는 일의 합의 최대값
    dp[0]=arr[0];
    for(int i=1; i<=x; ++i){
        dp[i]=max(dp[i-1],arr[i]);
    }
    for(int i=x+1; i<N; ++i){
        dp[i]=max(dp[i-1], dp[i-x-1]+arr[i]);
    }
    if(dp[N-1]>=M) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    ll sum=0;
    int flag=0; // 0 : normal, 1 : free!
    for(int i=0; i<N; ++i){
        cin>>arr[i];
        sum+=arr[i];
        if(arr[i]>=M) flag=1;
    }
    if(flag==1){
        cout << "Free!\n";
        return 0;
    }
    if(sum<M){
        cout << "-1\n";
        return 0;
    }
    int lo=0, hi=200001;
    while(lo<hi-1){
        int mid=(lo+hi)/2;
        if(f(mid)){
            lo=mid;
        }
        else{
            hi=mid;
        }
    }
    cout << lo << '\n';
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100000];
ll N, M;
ll max_=-1;
ll f(int K) {
    ll sum=K, cnt=1;
    for(int i=0; i<N; ++i){
        if(arr[i]>sum) {
            sum=K, cnt++;
        }
        sum-=arr[i];
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
        max_=max(max_, arr[i]);
    }
    ll lo=max_-1, hi=10000*100000;
    while(lo<hi-1){
        ll mid = (lo+hi)/2;
        if(f(mid)>M) lo=mid;
        else hi=mid;
    }
    cout << hi << '\n';
}
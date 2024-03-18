#include <bits/stdc++.h>
#define LEFT 0
#define RIGHT 1
using namespace std;
using ll=long long;
const ll INF = 987654321;
ll N, M;
vector<ll> arr;
ll dp[301][301][2]; // l, r, lr
ll f(ll l, ll r, ll lr, ll basket) { 
// 구간 왼쪽 l번째, 오른쪽 r번째에서 현재 lr 쪽에 있을 때, 
//남은 사탕 바구니의 개수가 basket개 일 때 최소한으로 잃는 사탕의 개수.
// l과 r이 0에서 시작해서 양쪽으로 가도록
    if(basket==0) return 0;
    ll &dpRef = dp[l][r][lr];
    if(dpRef!=-1) return dpRef;
    ll ret=INF;
    if(lr==LEFT) {
        if(l!=0){ // 왼쪽으로 갈 수 있을 때
            ret=min(ret, f(l-1, r, LEFT, basket-1) + (arr[l]-arr[l-1])*basket);
        }
        if(r!=N){ // 오른쪽으로 갈 수 있을 때
            ret=min(ret, f(l, r+1, RIGHT, basket-1) + (arr[r+1]-arr[l])*basket);
        }
    }
    else {
        if(l!=0){ // 왼쪽으로 갈 수 있을 때
            ret=min(ret, f(l-1, r, LEFT, basket-1) + (arr[r]-arr[l-1])*basket);
        }
        if(r!=N){ // 오른쪽으로 갈 수 있을 때
            ret=min(ret, f(l, r+1, RIGHT, basket-1) + (arr[r+1]-arr[r])*basket);
        }
    }
    return dpRef=ret;
}
int main(){
    cin>>N>>M;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; arr.push_back(a);
    }
    arr.push_back(0);
    sort(arr.begin(), arr.end());
    auto idx = lower_bound(arr.begin(), arr.end(), 0) - arr.begin();
    ll res=0;
    for(ll basket=0; basket<=N; ++basket) {
        memset(dp, -1, sizeof dp);
        res=max(res, basket*M - f(idx, idx, RIGHT, basket));
    }
    cout << res << '\n';
}
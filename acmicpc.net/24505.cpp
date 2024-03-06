#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll P = 1e9+7;
const ll MN = 100001;
ll seg[MN*4+1][12]; // 구간 i~j에서 k개의 원소 쌍의 개수
ll Query(ll L, ll R, ll j, ll n, ll l, ll r) {
    if(L<=l && r<=R) return seg[n][j];
    if(r<L || R<l) return 0;
    ll mid = (l+r)/2;
    return (Query(L, R, j, n*2, l, mid) + Query(L, R, j, n*2+1, mid+1, r))%P;
}
ll Update(ll idx, ll j, ll k, ll n, ll l, ll r){
    if(r<idx || idx<l) return seg[n][j];
    if(l==r) {
        seg[n][j]+=k;
        seg[n][j]%=P;
        return seg[n][j];
    }
    ll mid = (l+r)/2;
    return seg[n][j] = (Update(idx, j, k, n*2, l, mid) + Update(idx, j, k, n*2+1, mid+1, r))%P;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a;
        Update(a, 1, 1, 1, 1, MN);
        for(ll j=2; j<=11; ++j){
            ll temp=Query(1, a-1, j-1, 1, 1, MN);
            // cout << "Query of a="<<a<<", j="<<j<<", is : " << temp << '\n';
            Update(a, j, temp, 1, 1, MN);
        }
    }
    cout << Query(1, N, 11, 1, 1, MN) << '\n';
}
/*
1 4 5 3 5

숫자가 새로 들어올 때 세그트리를 갱신하고, 쿼리를 구함.
쿼리가 들어올 때 알 수 있는 것 : 현재 숫자보다 작은 수들의 개수.
dp[i][j] 갱신 : 현재 수(i)를 마지막으로 둘 때 원소 쌍이 j개일 때 쌍의 개수.
dp를 세그먼트 트리 형태로 누적된 값을 구해야 할 듯.
쿼리를 구할 때 현재 수보다 작은 수들 중 원소 쌍이 (j-1) 개인 수만큼 계속 더해주면 된다.

세그 트리 쿼리(with 원소 쌍 j)로 구하는 값 : 해당 구간에서 원소 쌍 j가 의미하는 dp 값의 합. (구간합)
세그 트리에 누적하는 값 : dp[j]. : 현재 수(arr[i])를 마지막으로 둘 때 원소 쌍이 j일 때 쌍의 개수.

*/
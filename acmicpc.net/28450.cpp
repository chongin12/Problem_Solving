#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dx[]={0,1};
ll dy[]={1,0};
ll dp[1001][1001]; // dp[i][j] : (i,j)에서 끝까지 갈 수 있는 최소 경로 합
ll arr[1001][1001];
ll N, M;
const ll INF = 1e18;
ll f(ll i, ll j){ // f(i, j) : (i,j)에서 끝까지 갈 수 있는 최소 경로 합
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll ret=INF;
    for(ll k=0; k<2; ++k){
        ll ni=i+dx[k];
        ll nj=j+dy[k];
        if(ni>=0 && ni<N && nj>=0 && nj<M) {
            ret=min(ret,f(ni,nj)+arr[i][j]);
        }
    }
    return dp[i][j]=ret;
}
void init(){
    for(ll i=0; i<1001; ++i){
        for(ll j=0; j<1001; ++j){
            dp[i][j]=-1;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    cin>>N>>M;
    for(ll i=0; i<N; ++i){
        for(ll j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    dp[N-1][M-1]=arr[N-1][M-1];
    ll H; cin>>H;
    ll res=f(0,0);
    if(res>H) cout << "NO\n";
    else cout << "YES\n" << res << '\n';
}
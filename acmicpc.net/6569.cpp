#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll dp[15][20000];
ll safeCache[20000];
void init(){
    for(int i=0; i<15; ++i){
        for(int j=0; j<20000; ++j){
            dp[i][j]=0;
        }
    }
    for(int i=0; i<20000; ++i){
        safeCache[i]=-1;
    }
}
bool safe(ll x, ll M){
    if(safeCache[x]!=-1) return safeCache[x];
    ll cnt=0;
    bool pass=true;
    for(ll k=1; k<(1<<M); k<<=1){
        if(x&k){
            if(cnt%2){
                pass=false;
                break;
            }
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    if(cnt%2) pass=false;
    return safeCache[x]=pass;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        ll N,M; cin>>N>>M;
        if(N==0 && M==0) break;
        init();
        if(N*M%2) {
            cout << "0\n";
            continue;
        }
        for(int j=0; j<(1<<M); ++j){
            if(safe(j, M)) dp[1][j]=1;
            // cout << "dp["<<1<<"]["<<j<<"]="<<dp[1][j]<<'\n';
        }
        for(ll i=2; i<=N; ++i){
            for(ll j=0; j<(1<<M); ++j){
                // j는 비트마스크이고, 0은 조각을 놓을 수 있음, 1은 조각을 놓을 수 없음(이미 채워짐)을 의미한다.
                // 우리의 목표는 dp[i][j]를 채우는 것
                for(ll k=0; k<(1<<M); ++k){
                    // 현재 j의 상태임. 다음 행은 k의 상태임. k의 상태인게 가능하려면 j의 비트가 하나라도 있으면 안됨. 또한 j|k에 대해 한번 더 검증 해줘야 함.
                    if(!(j&k) && safe(j|k, M)){
                        dp[i][j]+=dp[i-1][k];
                    }
                }
                // cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<'\n';
            }
            
        }
        cout << dp[N][0] << '\n';
    }
}
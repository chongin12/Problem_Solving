#include <bits/stdc++.h>
using namespace std;
int dp[2][10001];
int idx=0;
int nidx=1;
int V,C,K;
int k,Vk,Ck;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M; cin>>N>>M;
    for(int i=1; i<=N; ++i){
        cin>>V>>C>>K;
        for(int w=K; w>0; w/=2){
            k=w-(w>>1);
            Vk=V*k;
            Ck=C*k;
            for(int j=0; j<Vk; ++j){
                dp[nidx][j]=dp[idx][j];
            }
            for(int j=Vk; j<=M; ++j){
                dp[nidx][j]=max(dp[idx][j], dp[idx][j-Vk]+Ck);
            }
            nidx=!nidx;
            idx=!idx;
        }
    }
    cout << dp[idx][M] << '\n';
}
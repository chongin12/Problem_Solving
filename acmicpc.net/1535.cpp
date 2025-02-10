#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> v(21);
int dp[21][100];
int main(){
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        v[i].first = a;
    }
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        v[i].second=a;
    }
    for(int i=1; i<=N; ++i){
        for(int j=0; j<v[i].first; ++j){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=v[i].first; j<100; ++j){
            dp[i][j]=max(dp[i-1][j], dp[i-1][j-v[i].first]+v[i].second);
        }
    }
    cout << dp[N][99] << '\n';
}
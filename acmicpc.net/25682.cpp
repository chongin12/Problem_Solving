#include <bits/stdc++.h>
using namespace std;
vector<string> v={""};
int dp1[2001][2001];
int dp2[2001][2001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, K; cin>>N>>M>>K;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        v.push_back(" " + str);
    }
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            if(((i+j)%2==0 && v[i][j]=='B') || ((i+j)%2==1 && v[i][j]=='W')){
                dp1[i][j]=dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1]+1;
            }
            else {
                dp1[i][j]=dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1];
            }
        }
    }

    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            if(((i+j)%2==1 && v[i][j]=='B') || ((i+j)%2==0 && v[i][j]=='W')){
                dp2[i][j]=dp2[i-1][j]+dp2[i][j-1]-dp2[i-1][j-1]+1;
            }
            else {
                dp2[i][j]=dp2[i-1][j]+dp2[i][j-1]-dp2[i-1][j-1];
            }
        }
    }

    int res=987654321;
    for(int i=K; i<=N; ++i){
        for(int j=K; j<=M; ++j){
            int a=dp1[i][j]-dp1[i-K][j]-dp1[i][j-K]+dp1[i-K][j-K];
            int b=dp2[i][j]-dp2[i-K][j]-dp2[i][j-K]+dp2[i-K][j-K];
            res=min({a,b,res});
        }
    }
    cout << res << '\n';
}
#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> v;
int dp[21];
int main(){
    int N; cin>>N;
    int res=1;
    for(int i=0; i<N; ++i){
        int x1, x2; cin>>x1>>x2;
        v.push_back({x1,x2});
    }
    sort(v.begin(), v.end(), greater<pii>());
    dp[0]=1;
    for(int i=1; i<N; ++i){
        dp[i]=1;
        for(int j=0; j<i; ++j){
            if(v[i].first<v[j].first && v[i].second<v[j].second)
                dp[i]=max(dp[i],dp[j]+1);
            res=max(res,dp[i]);
        }
    }
    cout << res << '\n';
}

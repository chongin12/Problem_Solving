#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int dp[10001]; // dp[i] : i개를 만들 때 필요한 최소 횟수
set<int> s;
int f(int x){
    if(x<0) return INF;
    if(x==0) return 0;
    if(dp[x]) return dp[x];
    int ret=INF;
    for(auto it:s){
        ret=min(ret,f(x-it)+1);
    }
    return dp[x]=ret;
}
int main(){
    int N, M; cin>>N>>M;
    vector<int> v;
    for(int i=0; i<M; ++i){
        int a; cin>>a; v.push_back(a); s.insert(a);
    }
    for(int i=0; i<M; ++i){
        for(int j=0; j<M; ++j){
            if(i==j) continue;
            s.insert(v[i]+v[j]);
        }
    }
    // for(auto it:s){
    //     cout << it << '\n';
    // }
    int res=f(N);
    if(res==INF) cout << "-1\n";
    else cout << res << '\n';
}
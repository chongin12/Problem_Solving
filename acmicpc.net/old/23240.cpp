#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct grp{
    ll n;
    int col; // R:0, G:1, B:2
    bool dir;
    grp(ll n, int col, bool dir):n(n),col(col),dir(dir){}
    void toggle(){
        dir=!dir;
    }
};
ll dp[31]; // i번째를 뒤집으면 i-1번째와 i번째는 1번씩 더 해줘야 한다.
ll res;
vector<grp> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m; cin>>m;
    for(int i=0; i<m; ++i){
        char ch;
        ll a;
        cin>>ch>>a;
        if(ch=='R') v.push_back(grp(a,0,true));
        else if(ch=='G') v.push_back(grp(a,1,true));
        else v.push_back(grp(a,2,true));
        if(v.back().n==1) v.back().col=1;
    }

    if(m==1){
        if(v[0].col==2) cout << 2*v[0].n-1 << '\n';
        else cout << v[0].n << '\n';
        return 0;
    }

    dp[m-1]=1;
    for(int i=m-1; i>0; --i){
        dp[i-1]=2*dp[i];
        if((dp[i]%2==0 && v[i].col==0) || (dp[i]%2==1 && v[i].col==2)){
            dp[i-1]++;
            dp[i]++;
        }
        res+=dp[i]*v[i].n;
    }
    if((dp[0]%2==0 && v[0].col==0) || (dp[0]%2==1 && v[0].col==2)){
        res+=(dp[0]+1)*v[0].n-1;
    }
    else{
        res+=dp[0]*v[0].n;
    }
    cout << res << '\n';
    
}
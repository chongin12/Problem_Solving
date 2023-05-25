#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[100]; // dp[i] : i개가 있을 때 만들 수 있는 그룹 개수
int main(){
    ll N; cin>>N;
    string s; cin>>s;
    vector<ll> v;
    dp[2]=1;
    for(ll i=3; i<81; ++i){
        dp[i] = dp[i-1]+dp[i-2]+1;
    }

    ll prev=-2;
    for(ll i=3; i<s.size(); ++i){
        if(s[i-3]=='l' && s[i-2]=='o' && s[i-1]=='n' && s[i]=='g'){
            if(prev==i-4){
                v.back()+=1;
            }
            else{
                v.push_back(1);
            }
            prev=i;
        }
    }
    vector<ll> resv;
    for(auto it:v){
        // cout << it << '\n';
        if(it>=2) resv.push_back(dp[it]);
    }
    if(resv.size()==0) cout << "1\n";
    else{
        ll res=1;
        for(auto it:resv) res*=it+1;
        cout << res << '\n';
    }
}

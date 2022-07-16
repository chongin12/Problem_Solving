#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const ll MOD = 1000000007;
const int MN=500000;

ll dp[MN+10];
vector<pll> v; 
ll G;
void init(){
    for(int i=0; i<MN+10; ++i){
        dp[i]=-1;
    }
    v.clear();
}
bool cmp(pll a, pll b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
ll f(ll x, ll y) {
	ll ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= MOD;
		}
		x *= x;
		x %= MOD;
		y /= 2;
	}
	return ans;
}
ll combi(ll tn, ll tk){
    ll n=1;
	ll k=1;
	for(ll i=1; i<=tn; ++i){
		n *= i;
		n %= MOD;
	}
	for (ll i = 1; i <= tk; ++i) {
		k *= i;
		k %= MOD;
	}
	for (ll i = 1; i <= tn-tk; ++i) {
		k *= i;
		k %= MOD;
	}
	ll res = n * f(k, MOD - 2) % MOD;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        init();
        cout << "Case #"<<t<<endl;
        ll N,K; cin>>N>>K;
        
        vector<ll> input;
        ll a;
        ll acc=0;
        for(int i=0; i<N; ++i){
            cin>>a;
            input.push_back(a);
            acc+=a;
        }
        if(acc<0){
            for(int i=0; i<N; ++i){
                input[i]=-input[i];
            }
        }
        v.push_back({0,input[0]});
        for(int i=1; i<N; ++i){
            v.push_back({i,input[i]+v[i-1].second});
        }
        G=v.back().second;
        if(G%K){
            cout << "0" << endl;
            continue;
        }
        G/=K;
        pll lastpll=v.back();
        sort(v.begin(), v.end(), cmp);
        if(G==0){
            acc=0;
            ll cnt=0;
            for(int i=0; i<input.size(); ++i){
                acc+=input[i];
                if(acc==0) cnt++; 
            }
            
            cout << combi(cnt-1,K-1) << endl;
            continue;
        }
        else{
            for(int i=0; i<v.size(); ++i){
                if(v[i].second==G) dp[i]=1;
                else if(v[i].second<G) dp[i]=0;
                else break;
            }
        }
        auto pos=lower_bound(v.begin(), v.end(), lastpll, cmp) - v.begin();
        ll nowG=G+G;
        for(int i=0; i<=pos; ++i){
            if(dp[i]!=-1) continue;
            dp[i]=0;
            if(v[i].second<nowG) continue;
            if(nowG!=v[i].second) nowG+=G;
            if(nowG!=v[i].second) continue;
            ll ret=0;
            int pos2;
            if(i && v[i-1].second == v[i].second){
                ret+=dp[i-1];
                ret%=MOD;
                pos2=lower_bound(v.begin(), v.end(), pll(v[i-1].first,nowG-G), cmp)-v.begin();
            }
            else{
                pos2=lower_bound(v.begin(), v.end(), pll(0,nowG-G), cmp)-v.begin();
            }
            for(int j=pos2; j<=pos; ++j){
                if(v[j].second!=nowG-G) break;
                if(v[j].first>v[i].first) break;
                ret+=dp[j];
                ret%=MOD;
            }
            dp[i]=ret%MOD;
            // cout << "dp["<<i<<"]="<<dp[i]<<'\n';
        }
        if(dp[pos]==-1) dp[pos]=0;
        cout << dp[pos]%MOD << endl;
    }
}
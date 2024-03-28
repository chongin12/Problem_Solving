#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll P=1e9+7;
struct mat{
	vector<vector<ll> > v;
	ll size;
	mat(){}
	mat(ll size):size(size){
		v.clear();
		for(ll i=0; i<size; i+=1){
			v.push_back(vector<ll>());
			for(ll j=0; j<size; j+=1){
				v[i].push_back(0);
			}
		}
	}
	mat(vector<vector<ll> > vv){
		v.clear();
		size=vv.size();
		for(ll i=0; i<size; i+=1){
			v.push_back(vector<ll>());
			for(ll j=0; j<size; j+=1){
				v[i].push_back(0);
			}
		}
		for(ll i=0; i<vv.size(); i+=1){
			for(ll j=0; j<vv[i].size(); j+=1){
				v[i][j] = vv[i][j];
			}
		}
	}
};
mat matmul(mat a, mat b){
	ll n=a.v.size();
	mat ret=mat(n);
	for(ll i=0; i<n; i+=1){
		for(ll j=0; j<n; j+=1){
			for(ll k=0; k<n; k+=1){
				ret.v[i][j]+=((a.v[i][k]%P)*(b.v[k][j])%P)%P;
				ret.v[i][j]%=P;
			}
		}
	}
	return ret;
}
mat matsq(mat a, ll cnt){
	if(cnt==1) return a;
	mat m(a.size);
	for(ll i=0; i<a.size; i+=1){
		m.v[i][i]=1;
	}
	for(;cnt; cnt/=2, a=matmul(a,a)){
		if(cnt%2==1) m=matmul(m,a);
	}
	return m;
}
vector<mat> matv;
mat dp[101];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll N,T,D; cin>>T>>N>>D;
	mat res(N);
	for(ll i=0; i<N; i+=1){
		for(ll j=0; j<N; j+=1){
			if(i==j) {
				res.v[i][j]=1;
			}
			else {
				res.v[i][j]=0;
			}
		}
	}
	dp[0]=res;
	for(ll i=1; i<=T; i+=1){
		ll M; cin>>M;
		mat A(N);
		for(ll j=0; j<M; j+=1){
			ll a,b,c; cin>>a>>b>>c;
			a-=1; b-=1;
			A.v[a][b]=c;
		}
		dp[i]=matmul(dp[i-1],A);
	}
	res=matsq(dp[T],D/T);
	res=matmul(res,dp[D%T]);
	for(ll i=0; i<N; i+=1){
		for(ll j=0; j<N; j+=1){
			cout << res.v[i][j] << " ";
		}
		cout << '\n';
	}
}
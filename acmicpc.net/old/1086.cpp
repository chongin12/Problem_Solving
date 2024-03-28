#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using pll=pair<ll,ll>;
vector<pll> v;
vector<string> temp;
ll fact[20]; // nPr = n! / (n-r)!
ll N,K;
ll f(string str){
	ll m=1;
	ll res=0;
	for(int i=str.size()-1; i>=0; --i){
		ll x=str[i]-'0';
		res=(res+(x%K)*m)%K;
		m=(m*10)%K;
	}
	return res;
}
ll res1=0;//분자
ll res2=0;//분모

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll dp1[16][2510];
//dp1[i][j] : i번째 수 뒤에 0이 j만큼 있을 때 더할 수
ll dp4[32768][100];
//dp4[i][j] : i비트들을 사용하고, 나머지가 j인 수들의 개수
void bfs(){
	queue<int> q;
	int visit[40000]={0,};
	q.push(0);
	visit[0]=1;
	while(!q.empty()){
		int cur=q.front(); q.pop();
		// cout << "cur : " << cur << '\n';
		for(int i=0; i<N; ++i){
			if(cur & (1<<i)) continue;
			int nxtMask=cur+(1<<i);
			if(!visit[nxtMask]){
				q.push(nxtMask);
				visit[nxtMask]=1;
			}
			int len=0;
			for(int j=0; j<N; ++j){
				if(cur & (1<<j)) len+=v[j].second;
			}
			for(int j=0; j<K; ++j){
				dp4[nxtMask][(j+dp1[i][len])%K]+=dp4[cur][j];
			}
		}
	}
}
int main(){
	cin>>N;
	for(int i=0; i<N; ++i){
		string str; cin>>str;
		temp.push_back(str);
	}
	cin>>K;
	for(int i=0; i<N; ++i){
		v.push_back({f(temp[i]),temp[i].size()});
		// cout << v[i].first << ", "<<v[i].second << '\n';
	}
	fact[0]=1;
	for(ll i=1; i<=15; ++i){
		fact[i]=fact[i-1]*i;
	}
	for(int i=0; i<N; ++i){
		ll m=1;
		for(int j=0; j<2510; ++j){
			dp1[i][j]=(v[i].first*m)%K;
			m=(m*10)%K;
		}
	}
	for(int i=0; i<N; ++i){
		dp4[(1<<i)][v[i].first]+=1;
	}
	bfs();
	/*
	TODO: dp4 계산 후 결과 출력
	*/
	res2=fact[N];
	// for(int i=1; i<(1<<N); ++i){
	// 	res1+=dp4[i][0];
	// }
	res1=dp4[(1<<N)-1][0];
	// cout << res1 <<"/"<<res2<<'\n';
	cout << res1/gcd(res1,res2) << "/" << res2/gcd(res1,res2) << '\n';
}
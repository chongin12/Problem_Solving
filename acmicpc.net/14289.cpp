#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll MOD=1000000007;
ll n,m;
ll D;
ll res[50][50];
ll spare[50][50];
void resMul(ll a[50][50]){
	ll newArr[50][50]={0,};
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			for(int k=0; k<n; ++k){
				newArr[i][j]+=((res[i][k]%MOD)*(a[k][j]%MOD))%MOD;
				newArr[i][j]%=MOD;
			}
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			res[i][j]=newArr[i][j];
		}
	}
}
void spareMul(ll a[50][50]){
	ll newArr[50][50]={0,};
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			for(int k=0; k<n; ++k){
				newArr[i][j]+=((spare[i][k]%MOD)*(a[k][j]%MOD))%MOD;
				newArr[i][j]%=MOD;
			}
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			spare[i][j]=newArr[i][j];
		}
	}
}
void sq(){
	ll newRes[50][50]={0,};
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			for(int k=0; k<n; ++k){
				newRes[i][j]+=((res[i][k]%MOD)*(res[k][j]%MOD))%MOD;
				newRes[i][j]%=MOD;
			}
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			res[i][j]=newRes[i][j];
		}
	}
}
void dnc(){
	while(D!=1){
		if(D%2==1){
			D-=1;
			spareMul(res);
		}
		D/=2;
		sq();
	}
	resMul(spare);
	
	
	
}
int main(){
	cin>>n>>m;
	for(int i=0; i<m; ++i){
		int u,v;cin>>u>>v;
		res[u-1][v-1]=1;
		res[v-1][u-1]=1;
	}
	cin>>D;
	for(int i=0; i<n; ++i){
		spare[i][i]=1;
		
	}
	dnc();
	cout << res[0][0] << '\n';
}
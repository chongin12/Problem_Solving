#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll MOD=1000000007;
ll n;
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
	n=8;
	res[0][1]=1;
	res[1][0]=1;
	res[0][2]=1;
	res[2][0]=1;
	res[1][2]=1;
	res[2][1]=1;
	res[1][3]=1;
	res[3][1]=1;
	res[2][3]=1;
	res[3][2]=1;
	res[2][4]=1;
	res[4][2]=1;
	res[3][4]=1;
	res[4][3]=1;
	res[3][5]=1;
	res[5][3]=1;
	res[4][5]=1;
	res[5][4]=1;
	res[4][6]=1;
	res[6][4]=1;
	res[5][7]=1;
	res[7][5]=1;
	res[6][7]=1;
	res[7][6]=1;
	cin>>D;
	for(int i=0; i<n; ++i){
		spare[i][i]=1;
		
	}
	dnc();
	cout << res[0][0] << '\n';
}
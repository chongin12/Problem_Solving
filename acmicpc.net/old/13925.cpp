#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MN=100100;
const ll MOD = 1e9+7;
ll seg[MN*4+1];
ll lazy[2][MN*4+1];
ll Update(int idx, ll val, int n, int l, int r){
    if(idx<l || r<idx) return seg[n];
    if(l==r) return seg[n]=val;
    int mid=(l+r)/2;
    return seg[n]=(Update(idx, val, n*2, l, mid)%MOD+Update(idx,val,n*2+1,mid+1,r)%MOD)%MOD;
}
void UpdateLazy(int n, int l, int r){
    ll &mul=lazy[0][n];
    ll &sum=lazy[1][n];
    if(mul==1 && sum==0) return;
    if(l!=r){
        for(int i=n*2; i<=n*2+1; ++i){
            ll childMul = lazy[0][i], childSum = lazy[1][i];
            lazy[0][i] = childMul * mul; lazy[0][i]%=MOD;
            lazy[1][i] = childSum * mul + sum; lazy[1][i]%=MOD;
        }
    }
    seg[n]=(mul*seg[n]+(r-l+1)*sum)%MOD;
    mul=1, sum=0;
}
void UpdateRange(int L, int R, ll mul, ll sum, int n, int l, int r){
    UpdateLazy(n,l,r);
    if(R<l || r<L) return;

    if(L<=l && r<=R){
        lazy[0][n] *= mul; lazy[0][n]%=MOD;
        lazy[1][n] *= mul; lazy[1][n]%=MOD;
        lazy[1][n] += sum; lazy[1][n]%=MOD;
        UpdateLazy(n, l, r);
        return;
    }
    int mid=(l+r)/2;
    UpdateRange(L, R, mul, sum, n*2, l, mid);
    UpdateRange(L, R, mul, sum, n*2+1, mid+1, r);
    seg[n]=(seg[n*2]+seg[n*2+1])%MOD;
}
ll Query(int L, int R, int n, int l, int r){
    UpdateLazy(n,l,r);
    if(r<L || R<l) return 0;
    if(L<=l && r<=R) return seg[n]%MOD;
    int mid=(l+r)/2;
    return (Query(L,R,n*2,l,mid)%MOD+Query(L,R,n*2+1,mid+1,r)%MOD)%MOD;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<MN*4+1; ++i) lazy[0][i]=1, lazy[1][i]=0;
	int N,M; cin>>N;
	for(int i=1; i<=N; ++i){
		ll a; cin>>a;
		Update(i,a,1,1,N);
	}
    cin>>M;
	for(int i=0; i<M; ++i){
		int a; cin>>a;
		if(a==1){
			int b,c; ll d;
			cin>>b>>c>>d;
			UpdateRange(b,c,1,d,1,1,N);
		}
        else if(a==2){
			int b,c; ll d;
			cin>>b>>c>>d;
            UpdateRange(b,c,d,0,1,1,N);
		}
        else if(a==3){
			int b,c; ll d;
			cin>>b>>c>>d;
			UpdateRange(b,c,0,d,1,1,N);
		}
		else{
			int b,c; cin>>b>>c;
			cout << Query(b,c,1,1,N)%MOD << '\n';
		}
	}
}
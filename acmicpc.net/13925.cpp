#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MN=100100;
const ll MOD = 1e9+7;
ll seg[MN*4+1];
ll lazyplus[MN*4+1], lazymul[MN*4+1];
ll Update(int idx, ll val, int n, int l, int r){
    if(idx<l || r<idx) return seg[n];
    if(l==r) return seg[n]=val;
    int mid=(l+r)/2;
    return seg[n]=(Update(idx, val, n*2, l, mid)%MOD+Update(idx,val,n*2+1,mid+1,r)%MOD)%MOD;
}
void UpdateRangePlus(int L, int R, ll val, int n, int l, int r){
    if(lazymul[n]!=1){
        seg[n]*=lazymul[n];
        seg[n]%=MOD;
        if(l!=r){
            lazymul[n*2]*=lazymul[n];
            lazymul[n*2+1]*=lazymul[n];
            lazyplus[n*2]*=lazymul[n];
            lazyplus[n*2+1]*=lazymul[n];
            lazymul[n*2]%=MOD;
            lazymul[n*2+1]%=MOD;
            lazyplus[n*2]%=MOD;
            lazyplus[n*2+1]%=MOD;
        }
        lazymul[n]=1;
    }
    if(lazyplus[n]){
        seg[n]+=lazyplus[n]*(r-l+1)%MOD;
        seg[n]%=MOD;
        if(l!=r){
            lazyplus[n*2]+=lazyplus[n];
            lazyplus[n*2+1]+=lazyplus[n];
            lazyplus[n*2]%=MOD;
            lazyplus[n*2+1]%=MOD;
        }
        lazyplus[n]=0;
    }
    
    if(R<l || r<L) return;

    if(L<=l && r<=R){
        seg[n]+=val*(r-l+1);
        seg[n]%=MOD;
        if(l!=r){
            lazyplus[n*2]+=val;
            lazyplus[n*2+1]+=val;
            lazyplus[n*2]%=MOD;
            lazyplus[n*2+1]%=MOD;
        }
        return;
    }
    int mid=(l+r)/2;
    UpdateRangePlus(L,R,val,n*2,l,mid);
    UpdateRangePlus(L,R,val,n*2+1,mid+1,r);

    seg[n]=seg[n*2]+seg[n*2+1];
    seg[n]%=MOD;
}
void UpdateRangeMul(int L, int R, ll val, int n, int l, int r){
    if(lazymul[n]!=1){
        seg[n]*=lazymul[n];
        seg[n]%=MOD;
        if(l!=r){
            lazymul[n*2]*=lazymul[n];
            lazymul[n*2+1]*=lazymul[n];
            lazyplus[n*2]*=lazymul[n];
            lazyplus[n*2+1]*=lazymul[n];
            lazymul[n*2]%=MOD;
            lazymul[n*2+1]%=MOD;
            lazyplus[n*2]%=MOD;
            lazyplus[n*2+1]%=MOD;
        }
        lazymul[n]=1;
    }
    if(lazyplus[n]){
        seg[n]+=lazyplus[n]*(r-l+1)%MOD;
        seg[n]%=MOD;
        if(l!=r){
            lazyplus[n*2]+=lazyplus[n];
            lazyplus[n*2+1]+=lazyplus[n];
            lazyplus[n*2]%=MOD;
            lazyplus[n*2+1]%=MOD;
        }
        lazyplus[n]=0;
    }
    if(R<l || r<L) return;

    if(L<=l && r<=R){
        seg[n]*=val;
        seg[n]%=MOD;
        if(l!=r){
            lazymul[n*2]*=val;
            lazymul[n*2+1]*=val;
            lazyplus[n*2]*=val;
            lazyplus[n*2+1]*=val;
            lazymul[n*2]%=MOD;
            lazymul[n*2+1]%=MOD;
            lazyplus[n*2]%=MOD;
            lazyplus[n*2+1]%=MOD;
        }
        return;
    }
    int mid=(l+r)/2;
    UpdateRangeMul(L,R,val,n*2,l,mid);
    UpdateRangeMul(L,R,val,n*2+1,mid+1,r);

    seg[n]=(seg[n*2]+seg[n*2+1])%MOD;
}
ll Query(int L, int R, int n, int l, int r){
    if(lazymul[n]!=1){
        seg[n]*=lazymul[n];
        seg[n]%=MOD;
        if(l!=r){
            lazymul[n*2]*=lazymul[n];
            lazymul[n*2+1]*=lazymul[n];
            lazyplus[n*2]*=lazymul[n];
            lazyplus[n*2+1]*=lazymul[n];

            lazymul[n*2]%=MOD;
            lazymul[n*2+1]%=MOD;
            lazyplus[n*2]%=MOD;
            lazyplus[n*2+1]%=MOD;
        }
        lazymul[n]=1;
    }
    if(lazyplus[n]){
        seg[n]+=(r-l+1)*lazyplus[n]%MOD;
        seg[n]%=MOD;
        if(l!=r){
            lazyplus[n*2]+=lazyplus[n];
            lazyplus[n*2+1]+=lazyplus[n];

            lazyplus[n*2]%=MOD;
            lazyplus[n*2+1]%=MOD;
        }
        lazyplus[n]=0;
    }
    if(r<L || R<l) return 0;
    if(L<=l && r<=R) return seg[n];
    int mid=(l+r)/2;
    return (Query(L,R,n*2,l,mid)%MOD+Query(L,R,n*2+1,mid+1,r)%MOD)%MOD;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<MN*4+1; ++i) lazymul[i]=1;
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
			UpdateRangePlus(b,c,d,1,1,N);
		}
        else if(a==2){
			int b,c; ll d;
			cin>>b>>c>>d;
			UpdateRangeMul(b,c,d,1,1,N);
		}
        else if(a==3){
			int b,c; ll d;
			cin>>b>>c>>d;
			UpdateRangeMul(b,c,0,1,1,N);
			UpdateRangePlus(b,c,d,1,1,N);
		}
		else{
			int b,c; cin>>b>>c;
			cout << Query(b,c,1,1,N)%MOD << '\n';
		}
	}
}
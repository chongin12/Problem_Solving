#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MN=1000000;
ll seg[MN*4+1];
ll lazy[MN*4+1];
ll Update(int idx, ll val, int n, int l, int r){
    if(idx<l || r<idx) return seg[n];
    if(l==r) return seg[n]=val;
    int mid=(l+r)/2;
    return seg[n]=Update(idx, val, n*2, l, mid)^Update(idx,val,n*2+1,mid+1,r);
}
void UpdateRange(int L, int R, ll val, int n, int l, int r){
    if(lazy[n]){
        if((r-l+1)%2) seg[n]^=lazy[n];
        if(l!=r){
            lazy[n*2]^=lazy[n];
            lazy[n*2+1]^=lazy[n];
        }
        lazy[n]=0;
    }
    if(R<l || r<L) return;

    if(L<=l && r<=R){
        if((r-l+1)%2) seg[n]^=val;
        if(l!=r){
            lazy[n*2]^=val;
            lazy[n*2+1]^=val;
        }
        return;
    }
    int mid=(l+r)/2;
    UpdateRange(L,R,val,n*2,l,mid);
    UpdateRange(L,R,val,n*2+1,mid+1,r);

    seg[n]=seg[n*2]^seg[n*2+1];
}
ll Query(int L, int R, int n, int l, int r){
    if(lazy[n]){
        if((r-l+1)%2) seg[n]^=lazy[n];
        if(l!=r){
            lazy[n*2]^=lazy[n];
            lazy[n*2+1]^=lazy[n];
        }
        lazy[n]=0;
    }
    if(r<L || R<l) return 0;
    if(L<=l && r<=R) return seg[n];
    int mid=(l+r)/2;
    return Query(L,R,n*2,l,mid)^Query(L,R,n*2+1,mid+1,r);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        Update(i+1,a,1,1,N);
    }
    int M; cin>>M;
    for(int i=0; i<M; ++i){
        int ch; cin>>ch;
        if(ch==1){
            int a,b; ll c; cin>>a>>b>>c; a++,b++;
            if(a>b) swap(a,b);
            UpdateRange(a,b,c,1,1,N);
        }
        else{
            int a,b; cin>>a>>b; a++,b++;
            if(a>b) swap(a,b);
            cout << Query(a,b,1,1,N) << '\n';
        }
    }
}
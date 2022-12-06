#include <bits/stdc++.h>
using namespace std;
const int MN=4600000;
const int INF=987654321;
int segMax[MN*4+1];
int segMin[MN*4+1];
int lazy[MN*4+1];
void updateLazy(int L, int R, int val, int n, int l, int r){
    if(lazy[n]){
        segMax[n]+=lazy[n];
        segMin[n]+=lazy[n];
        if(l!=r){
            lazy[n*2]+=lazy[n];
            lazy[n*2+1]+=lazy[n];
        }
        lazy[n]=0;
    }
    if(r<L || R<l) return;
    if(L<=l && r<=R){
        segMax[n]+=val;
        segMin[n]+=val;
        if(l!=r){
            lazy[n*2]+=val;
            lazy[n*2+1]+=val;
        }
        return;
    }
    int mid=(l+r)/2;
    updateLazy(L, R, val, n*2, l, mid);
    updateLazy(L, R, val, n*2+1, mid+1, r);
    segMax[n]=max(segMax[n*2], segMax[n*2+1]);
    segMin[n]=min(segMin[n*2], segMin[n*2+1]);
}
int queryMaxLazy(int L, int R, int n, int l, int r){
    if(lazy[n]){
        segMax[n]+=lazy[n];
        segMin[n]+=lazy[n];
        if(l!=r){
            lazy[n*2]+=lazy[n];
            lazy[n*2+1]+=lazy[n];
        }
        lazy[n]=0;
    }
    if(r<L || R<l) return 0;
    if(L<=l && r<=R) return segMax[n];
    int mid=(l+r)/2;
    return max(queryMaxLazy(L, R, n*2, l, mid), queryMaxLazy(L, R, n*2+1, mid+1, r));
}
int queryMinLazy(int L, int R, int n, int l, int r){
    if(lazy[n]){
        segMax[n]+=lazy[n];
        segMin[n]+=lazy[n];
        if(l!=r){
            lazy[n*2]+=lazy[n];
            lazy[n*2+1]+=lazy[n];
        }
        lazy[n]=0;
    }
    if(r<L || R<l) return INF;
    if(L<=l && r<=R) return segMin[n];
    int mid=(l+r)/2;
    return min(queryMinLazy(L, R, n*2, l, mid), queryMinLazy(L, R, n*2+1, mid+1, r));
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int C, N, O; cin>>C>>N>>O; C++;
    while(O--){
        string str; cin>>str;
        if(str[0]=='s'){
            int X; cin>>X; X++;
            cout << queryMaxLazy(X, X, 1, 1, C) << '\n';
        }
        else if(str[0]=='g'){
            int A, B, S; cin>>A>>B>>S; A++, B++;
            if(S>=0) {
                int k=queryMaxLazy(A, B, 1, 1, C);
                S=min(S, N-k);
            }
            else{
                int k=queryMinLazy(A, B, 1, 1, C);
                S=max(S, 0-k);
            }
            updateLazy(A, B, S, 1, 1, C);
            cout << S << '\n';
        }
        else{
            int X, S; cin>>X>>S; X++;
            if(S>=0) {
                int k=queryMaxLazy(X, X, 1, 1, C);
                S=min(S, N-k);
            }
            else{
                int k=queryMinLazy(X, X, 1, 1, C);
                S=max(S, 0-k);
            }
            updateLazy(X, X, S, 1, 1, C);
            cout << S << '\n';
        }
    }
}
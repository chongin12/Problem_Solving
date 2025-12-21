#include <bits/stdc++.h>
using namespace std;
int A[10001];
int K;
int res1, res2;
int Partition(int p, int r) {
    int x = A[r];
    int i=p-1;
    for(int j=p; j<r; ++j){
        if(A[j]<=x) {
            if(K==1){
                res1=A[i+1];
                res2=A[j];
            }
            K--;
            swap(A[++i],A[j]);
        }
    }
    if(i+1!=r) {
        if(K==1){
            res1=A[i+1];
            res2=A[r];
        }
        K--;
        swap(A[i+1],A[r]);
    }
    return i+1;
}
int Select(int p, int r, int q){
    if(p==r) return A[p];
    int t=Partition(p, r);
    int k=t-p+1;
    if(q<k) return Select(p, t-1, q);
    else if(q==k) return A[t];
    else return Select(t+1, r, q-k);
}
int main(){
    int N, Q; cin>>N>>Q>>K;
    for(int i=0; i<N; ++i) cin>>A[i];
    Select(0, N-1, Q);
    if(K>1) cout << "-1\n";
    else cout << min(res1,res2) << " " << max(res1,res2) << '\n';
}
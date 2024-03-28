#include <bits/stdc++.h>
using namespace std;
int recip(int a){
    if(a==0) return 0;
    if(a>0) return 1;
    return -1;
}
int main(){
    int N, M; cin>>N>>M;
    vector<int> v(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    int cnt=0;
    int res=0;
    sort(v.begin(), v.end());
    int l=0, r=N-1;
    if(abs(v[l])>abs(v[r])){
        res+=abs(v[l]);
        int k=recip(v[l]);
        for(int i=0; i<M && i<N && k==recip(v[l]); ++i, ++l);
    }
    else{
        res+=abs(v[r]);
        int k=recip(v[r]);
        for(int i=0; i<M && l<=r && k==recip(v[r]); ++i, --r);
    }
    while(l<=r){
        if(abs(v[l])>abs(v[r])){
            res+=abs(v[l])*2;
            int k=recip(v[l]);
            for(int i=0; i<M && l<=r && k==recip(v[l]); ++i, ++l);
        }
        else{
            res+=abs(v[r])*2;
            int k=recip(v[r]);
            for(int i=0; i<M && l<=r && k==recip(v[r]); ++i, --r);
        }
    }
    cout << res << '\n';
}
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int r, g;
};
Node arr[1001];
int main(){
    int N, L; cin>>N>>L;
    fill(arr, arr+1001, Node({0,0}));
    for(int i=0; i<N; ++i){
        int a,b,c; cin>>a>>b>>c;
        arr[a]={b,c};
    }
    int t=1;
    for(int i=1; i<=L; ++i, ++t){
        // cout << "i="<<i<<", t="<<t<<'\n';
        if(arr[i].r==0) continue;
        if(t%(arr[i].r + arr[i].g)>=arr[i].r){
            continue;
        }
        else {
            --i;
            continue;
        }
    }
    cout << t-1 << '\n';
}
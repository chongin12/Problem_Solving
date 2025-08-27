#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    int Q; cin>>Q;
    while(Q--){
        int what; cin>>what;
        if(what==1){
            int l, r, k; cin>>l>>r>>k;
            int cnt=0;
            for(int i=l-1; i<=r-1; ++i){
                if(v[i]==k) cnt++;
            }
            cout << cnt << '\n';
        }
        else {
            int l, r; cin>>l>>r;
            for(int i=l-1; i<=r-1; ++i){
                v[i]=0;
            }
        }
    }
}
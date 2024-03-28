#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    vector<int> v(N);
    for(int i=0; i<N; ++i) cin>>v[i];
    int S; cin>>S;
    for(int i=0; i<N; ++i){
        int val=v[i], idx=i;
        for(int j=i+1; j<N; ++j){
            if(j-i<=S && val<v[j]){
                val=v[j];
                idx=j;
            }
        }
        S-=idx-i;
        for(int j=idx; j>i; --j){
            swap(v[j], v[j-1]);
        }
    }
    for(auto it:v) cout << it << ' ';
    cout << '\n';
}
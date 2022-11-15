#include <bits/stdc++.h>
using namespace std;
map<int,int> m;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int w=0; w<N; ++w){
        int i,k; char j; cin>>i>>j>>k;
        if(j=='L'){
            m[i]=i-k;
        }
        else{
            m[i]=i+k;
        }
    }
    int cur; cin>>cur;
    for(int i=0; i<N; ++i){
        cur=m[cur];
    }
    cout << cur << '\n';
}
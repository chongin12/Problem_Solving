#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    vector<int> v(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    int prv=v[N-1];
    int res=1;
    for(int i=N-2; i>=0; --i){
        if(prv<v[i]) {
            res++;
            prv=v[i];
        }
    }
    cout << res << '\n';
}
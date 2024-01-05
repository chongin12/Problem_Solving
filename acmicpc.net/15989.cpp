#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        int res=0;
        for(int i=0; i*3<=N; ++i){
            res+=(N-i*3)/2+1;
        }
        cout << res << '\n';
    }
}
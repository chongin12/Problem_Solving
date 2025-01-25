#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int A, B, C; cin>>A>>B>>C;
        int AB, BC, CA; cin>>AB>>BC>>CA;
        int res=0;
        for(int i=0; i<=min(A,B); ++i){
            for(int j=0; j<=min(B-i,C); ++j){
                int k=min(C-j,A-i);
                // cout << "i : " << i << ", j : " << j << ", k : " << k << '\n';
                res=max(res,AB*i+BC*j+CA*k);
            }
        }
        cout << res << '\n';
    }
}
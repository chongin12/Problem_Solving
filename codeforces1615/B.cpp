#include <bits/stdc++.h>
using namespace std;
int psum[200002][20];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for(int i=1; i<=200000; ++i){
        int temp=i;
        for(int j=0; j<20; ++j){
            
            if(temp%2==1) psum[i][j]=psum[i-1][j]+1;
            else psum[i][j]=psum[i-1][j];
            temp/=2;
            // cout << "psum["<<i<<"]["<<j<<"]="<<psum[i][j]<<'\n';
        }
    }
    while(t--){
        int a,b; cin>>a>>b;
        int res=987654321;
        for(int i=0; i<20; ++i){
            res=min(res,b-a+1-(psum[b][i]-psum[a-1][i]));
        }
        cout << res << '\n';
    }
}
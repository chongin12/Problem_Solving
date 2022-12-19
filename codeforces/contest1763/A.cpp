#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> cnt(11);
        for(int i=0; i<n; ++i){
            int a; cin>>a;
            int c=1;
            for(int j=0; j<10; ++j, c<<=1){
                if(c>a) break;
                if(a&c) cnt[j]++;
            }
        }
        int c=1;
        int mx=0;
        int mn=0;
        for(int j=0; j<10; ++j, c<<=1){
            if(cnt[j]==0) continue;
            if(cnt[j]==n) {
                mx+=c;
                mn+=c;
                continue;
            }
            mx+=c;
        }
        cout << mx-mn << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        string str; cin>>str;
        int cnt0=0, cnt1=0;
        for(int i=0; i<n-1; ++i){
            if(str[i]=='0') cnt0++;
            else cnt1++;
            int x=2+i;
            if(cnt0==0 || cnt1==0){
                cout << "1 ";
            }
            else cout << x-1 << " ";
        }
        cout << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    int N=str.size();
    int r0=0, r1=0;
    for(int i=1; i<N; ++i){
        if(str[i]!=str[i-1]){
            if(str[i-1]=='0') r0++;
            else r1++;
        }
    }
    if(str[N-1]=='0') r0++;
    else r1++;
    cout << min(r0,r1) << '\n';
}
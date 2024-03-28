#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int N,M,a,prev,b; cin>>N>>M;
    bool flag=true;
    for(int i=0; i<M && flag; ++i){
        cin>>a>>prev;
        for(int j=1; j<a && flag; ++j){
            cin>>b;
            if(prev<b) {
                flag=false;
                break;
            }
            prev=b;
        }
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
}
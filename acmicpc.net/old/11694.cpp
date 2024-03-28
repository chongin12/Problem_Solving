#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    int res=0;
    int cnt=0;
    bool flag=true;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(a==1) cnt++;
        if(a>=2) flag=false;
        res^=a;
    }
    if(flag){
        if(cnt%2) cout << "cubelover\n";
        else cout << "koosaga\n";
    }
    else{
        if(res==0) cout << "cubelover\n";
        else cout << "koosaga\n";
    }

}
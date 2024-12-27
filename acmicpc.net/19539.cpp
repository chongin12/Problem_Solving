#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    int sum=0;
    int cnt=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a; sum+=a;
        cnt+=a/2;
    }
    bool res=false;
    if(sum%3==0 && cnt>=sum/3) res=true;
    if(res) cout << "YES\n";
    else cout << "NO\n";
}
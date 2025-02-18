#include <bits/stdc++.h>
using namespace std;
int count(int x){
    int ret=0;
    while(x){
        if(x%2) ret++;
        x/=2;
    }
    return ret;
}
int main(){
    int N, K; cin>>N>>K;
    for(int i=0; i<100000000; ++i){
        if(count(i+N)<=K){
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}
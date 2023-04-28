#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b; cin>>a>>b;
    int k=0;
    for(int i=0; i<10; ++i){
        if((a&(1<<i)) ^ (b&(1<<i))){
            k+=(1<<i);
        }
    }
    cout << k <<'\n';
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, k=0; cin>>N;
    for(int i=1; i<550000;++i){
        k=(k*10+1)%N;
        if(k==0){
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}
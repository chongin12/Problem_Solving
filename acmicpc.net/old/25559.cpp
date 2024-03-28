#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    if(N==1) cout << "1\n";
    else if(N%2) cout << "-1\n";
    else{
        cout << N << " ";
        for(int i=1; i<N; ++i){
            if(i%2) cout << N-i << " ";
            else cout << i << ' ';
        }
        cout << '\n';
    }
}
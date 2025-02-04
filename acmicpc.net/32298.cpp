#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M; cin>>N>>M;
    for(int i=0; i<N; ++i){
        cout << M*(i+2) << " ";
    }
    cout << '\n';
}
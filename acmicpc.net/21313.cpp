#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    for(int i=0; i<N/2; ++i){
        cout << "1 2 ";
    }
    if(N%2==1){
        cout << "3";
    }
    cout << '\n';
}
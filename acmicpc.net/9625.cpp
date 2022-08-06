#include <bits/stdc++.h>
using namespace std;
int main(){
    int A=1,B=0;
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int tempA=B;
        int tempB=B+A;
        A=tempA;
        B=tempB;
    }
    cout << A << " " << B << '\n';
}
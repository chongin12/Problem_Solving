#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        cout << "Case #"<<t<<"\n";
        int N, A, B; cin>>N>>A>>B;
        if(A<B) swap(A,B);
        int nA=0, nB=N/B;
        while(nA*A+nB*B!=N){
            if(nA*A+nB*B>N){
                nB--;
            }
            else{
                nA++;
            }
        }
        cout << nA+nB << '\n';
    }
}
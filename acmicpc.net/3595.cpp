#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    int res=987654321;
    int ri, rj, rk;
    for(int i=1; i*i*i<=N; ++i){
        for(int j=i; i*j*j<=N; ++j){
            if(i*j>N) break;
            for(int k=j; k<=N; ++k){
                if(i*j*k>N) break;
                if(i*j*k==N){
                    if(res>i*j*2+i*k*2+j*k*2){
                        res=i*j*2+i*k*2+j*k*2;
                        ri=i, rj=j, rk=k;
                    }
                }
            }
        }
    }
    cout << ri << " " << rj << " " << rk << '\n';
}
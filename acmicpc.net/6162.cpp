#include <bits/stdc++.h>
using namespace std;
int main(){
    int K; cin>>K;
    for(int i=0; i<K; ++i){
        cout << "Data Set "<<i+1 << ":\n";
        int E, A; cin>>E>>A;
        if(E<=A){
            cout << "no drought\n";
        }
        else {
            int cnt=0;
            int q=5;
            int qcnt=0;
            while(E>A*q){
                q*=5;
                qcnt++;
            }
            for(int j=0; j<qcnt; ++j){
                cout << "mega ";
            }
            cout << "drought\n";
        }
        cout << '\n';
    }
}
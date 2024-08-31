#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    for(int i=0; i<5*N; ++i){
        for(int j=0; j<5*N; ++j){
            if(i>=N && i<4*N && j>=N && j<4*N){
                cout << " ";
            }
            else {
                cout << "@";
            }
        }
        cout << '\n';
    }
}
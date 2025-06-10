#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    for(int i=0; i<5*N; ++i){
        if(i/N==2){
            for(int j=0; j<3*N; ++j){
                cout << "@";
            }
        }
        else if(i/N==0 || i/N==4) {
            for(int j=0; j<N; ++j){
                cout << "@";
            }
            for(int j=0; j<3*N; ++j){
                cout << " ";
            }
            for(int j=0; j<N; ++j){
                cout << "@";
            }
        } else {
            for(int j=0; j<N; ++j){
                cout << "@";
            }
            for(int j=0; j<2*N; ++j){
                cout << " ";
            }
            for(int j=0; j<N; ++j){
                cout << "@";
            }
        }
        cout << '\n';
    }
}
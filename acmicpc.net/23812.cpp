#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    for(int i=0; i<N*5; ++i){
        for(int j=0; j<N*5; ++j){
            if(j/N==0 || j/N==4 || i/N==1 || i/N==3){
                cout << "@";
            }
            else{
                cout << " ";
            }
        }
        cout << '\n';
    }
}
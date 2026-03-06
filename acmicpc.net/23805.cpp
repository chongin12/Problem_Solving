#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    for(int i=0; i<5; ++i){
        for(int j=0; j<N; ++j){
            for(int k=0; k<5; ++k){
                for(int w=0; w<N; ++w){
                    if(k%2==0 || i==0 && k==1 || i==4 && k==3){
                        cout << "@";
                    }
                    else {
                        cout << " ";
                    }
                }
            }
            cout << '\n';
        }
    }
}
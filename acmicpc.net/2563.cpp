#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a, b; cin>>a>>b;
        for(int j=0; j<10; ++j){
            for(int k=0; k<10; ++k){
                arr[a+j][b+k]=1;
            }
        }
    }
    int res=0;
    for(int i=0; i<101; ++i){
        for(int j=0; j<101; ++j){
            if(arr[i][j]) res++;
        }
    }
    cout << res << '\n';
}
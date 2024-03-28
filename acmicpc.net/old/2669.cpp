#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int main(){
    for(int i=0; i<4; ++i){
        int a,b,c,d; cin>>a>>b>>c>>d;
        for(int j=a; j<c; ++j){
            for(int k=b; k<d; ++k){
                arr[j][k]=1;
            }
        }
    }
    int cnt=0;
    for(int i=0; i<101; ++i){
        for(int j=0; j<101; ++j){
            if(arr[i][j]) cnt++;
        }
    }
    cout << cnt << '\n';
}
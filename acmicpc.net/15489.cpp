#include <bits/stdc++.h>
using namespace std;
int arr[62][62];
int main(){
    int R, C, W; cin>>R>>C>>W;
    for(int i=1; i<62; ++i){
        arr[i][1]=1;
        arr[i][i]=1;
        for(int j=2; j<i; ++j){
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    }
    int ret=0;
    for(int i=1; i<=W; ++i){
        for(int j=1; j<=i; ++j){
            ret+=arr[i+R-1][j+C-1];
        }
    }
    cout << ret << '\n';
}
#include <bits/stdc++.h>
using namespace std;
int arr[301][301];
int arr2[301][301];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>arr[i][j];
        }
    }
    int res=0;
    int a;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>arr2[i][j];
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int temp=0;
            for(int k=0; k<n; ++k){
                temp|=(arr[i][k] & arr2[k][j]);
            }
            if(temp) res++;
        }
    }
    cout << res << '\n';
}
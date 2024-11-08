#include <bits/stdc++.h>
using namespace std;
int arr[301][301];
int avail[301][301];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>M>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
        if(i==0){
            for(int j=0; j<M; ++j){
                if(arr[i][j]==0) break;
                avail[i][j]=1;
            }
        }
        else {
            for(int j=0; j<M; ++j){
                if(arr[i][j]==0) continue;
                if(avail[i-1][j]) avail[i][j]=1;
                if(j!=0 && avail[i][j-1]) avail[i][j]=1; 
            }
        }
    }
    if(avail[N-1][M-1]) cout << "Yes\n";
    else cout << "No\n";
}
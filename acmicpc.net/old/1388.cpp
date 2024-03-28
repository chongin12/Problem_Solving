#include <bits/stdc++.h>
using namespace std;
int res=0;
int visited[51][51];
int arr[51][51];
int main(){
    int N, M; cin>>N>>M;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        for(int j=0; j<M; ++j){
            if(str[j]=='-') arr[i][j]=0;
            else arr[i][j]=1;
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(visited[i][j]) continue;
            res++;
            visited[i][j]=1;
            if(arr[i][j]==0){
                for(int k=j+1; k<M; ++k){
                    if(arr[i][k]!=0) break;
                    visited[i][k]=1;
                }
            }
            else {
                for(int k=i+1; k<N; ++k){
                    if(arr[k][j]!=1) break;
                    visited[k][j]=1;
                }
            }
        }
    }
    cout << res << '\n';
}
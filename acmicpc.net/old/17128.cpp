#include <bits/stdc++.h>
using namespace std;
int arr[200001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin>>N>>Q;
    for(int i=0; i<N; ++i){
        arr[i]=1;
    }
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        for(int j=0; j<4; ++j){
            arr[(i-j+N)%N]*=a;
        }
    }
    int res=0;
    for(int i=0; i<N; ++i){
        res+=arr[i];
    }
    for(int i=0; i<Q; ++i){
        int a; cin>>a;
        for(int j=0; j<4; ++j){
            res-=arr[(a-1-j+N)%N]*2;
            arr[(a-1-j+N)%N]*=-1;
        }
        cout << res << '\n';
    }
}
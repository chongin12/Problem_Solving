#include <bits/stdc++.h>
using namespace std;
int acc[10];
int arr[10];
int N,M;
void f(int cur){
    if(cur==M){
        for(int i=0; i<M; ++i){
            cout << arr[acc[i]-1] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=N; ++i){
        acc[cur]=i;
        f(cur+1);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    sort(arr, arr+N);
    f(0);
}
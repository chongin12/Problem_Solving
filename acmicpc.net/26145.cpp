#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main(){
    int N, M; cin>>N>>M;
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
    }
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N+M; ++j){
            int a; cin>>a;
            arr[i]-=a;
            arr[j]+=a;
        }
    }
    for(int j=1; j<=N+M; ++j){
        cout << arr[j] << " ";
    }
    cout << '\n';
}
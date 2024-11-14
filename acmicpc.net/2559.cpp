#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main(){
    int N, K; cin>>N>>K;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    int temp=0;
    for(int i=0; i<K; ++i) temp+=arr[i];
    int res=temp;
    for(int j=K; j<N; ++j){
        temp=temp+arr[j]-arr[j-K];
        res=max(temp, res);
    }
    cout << res << '\n';
}
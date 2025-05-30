#include <bits/stdc++.h>
using namespace std;
vector<int> v={0};
int arr[101][101];
int main(){
    int N, M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int a; cin>>a; v.push_back(a);
    }
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            cin>>arr[i][j];
        }
    }
    int cnt=0;
    for(int i=2; i<=M; ++i){
        cnt+=arr[v[i-1]][v[i]];
    }
    cout << cnt << '\n';
}
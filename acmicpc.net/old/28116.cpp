#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int res[1000000];
int loc[1000000];
int arr[1000000];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        arr[i]=a;
        loc[a]=i;
    }
    for(int i=1; i<=N; ++i){
        // arr[i]와 arr[loc[i]]의 위치 바꿔야 함.
        res[arr[loc[i]]]+=loc[i]-i;
        res[arr[i]]+=loc[i]-i;
        loc[arr[i]]=loc[i];
        arr[loc[i]] = arr[i];
    }
    for(int i=1; i<=N; ++i){
        cout << res[i] << ' ';
    }
    cout << '\n';
}
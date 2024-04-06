#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int marr[1000001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(a<0){
            marr[-a]++;
        }
        else {
            arr[a]++;
        }
    }
    for(int i=1000000; i>0; --i){
        for(int j=0; j<marr[i]; ++j){
            cout << -i << '\n';
        }
    }
    for(int i=0; i<1000001; ++i){
        for(int j=0; j<arr[i]; ++j){
            cout << i << '\n';
        }
    }
}
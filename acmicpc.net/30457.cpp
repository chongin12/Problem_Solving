#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main(){
    int N; cin>>N;
    int cnt=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        arr[a]++;
    }
    for(int i=1; i<=1000; ++i){
        if(arr[i]) cnt++, arr[i]--;
    }
    for(int i=1000; i>0; --i){
        if(arr[i]) cnt++, arr[i]--;
    }
    cout << cnt << '\n';
}
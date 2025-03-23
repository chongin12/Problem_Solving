#include <bits/stdc++.h>
using namespace std;
int arr[105][105];
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a, b; cin>>a>>b;
        a++, b++;
        for(int i=a; i<a+10; ++i){
            for(int j=b; j<b+10; ++j){
                arr[i][j] = 1;
            }
        }
    }
    int cnt=0;
    for(int i=1; i<103; ++i){
        for(int j=1; j<103; ++j){
            if(arr[i][j]) continue;
            if(arr[i+1][j]) cnt++;
            if(arr[i-1][j]) cnt++;
            if(arr[i][j+1]) cnt++;
            if(arr[i][j-1]) cnt++;
        }
    }
    cout << cnt << '\n';
}
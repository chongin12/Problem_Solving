#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int N;
int f(int x){
    int r=1;
    while(1){
        if(x-r<0 || x+r>=N) break;
        if(arr[x-r]!=arr[x+r]) break;
        if(arr[x-r]>=arr[x-r+1]) break;
        r++;
    }
    return r*2-1;
}
int ff(int x1, int x2){
    if(arr[x1]!=arr[x2]) return 0;
    int r=1;
    while(1){
        if(x1-r<0 || x2+r>=N) break;
        if(arr[x1-r]!=arr[x2+r]) break;
        if(arr[x1-r]>=arr[x1-r+1]) break;
        r++;
    }
    return r*2;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N;

    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    int res=0;
    for(int i=0; i<N; ++i){
        res=max(res,f(i));
        if(i!=N-1) res=max(res,ff(i,i+1));
    }
    cout << res << '\n';
}
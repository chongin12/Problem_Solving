#include <bits/stdc++.h>
using namespace std;
int arr[7100001];
int main(){
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        arr[i]=i+1;
    }
    arr[N]=1;
    int cur=1, cnt=0;
    while(cnt<N-1){
        int a=cur;
        int b=arr[a];
        int c=arr[b];
        arr[a]=c;
        cur=c;
        cnt++;
    }
    cout << cur << '\n';
}
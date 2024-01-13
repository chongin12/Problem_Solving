#include <bits/stdc++.h>
using namespace std;
const int MN=100001;
int type[MN];
int arr[MN];
queue<int> q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        cin>>type[i];
    }
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    for(int i=N-1; i>=0; --i){
        if(type[i]==0) q.push(arr[i]);
    }
    int M; cin>>M;
    for(int i=0; i<M; ++i){
        int a; cin>>a;
        q.push(a);
        cout << q.front() << " ";
        q.pop();
    }
    cout << '\n';
}
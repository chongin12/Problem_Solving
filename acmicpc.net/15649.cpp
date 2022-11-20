#include <bits/stdc++.h>
using namespace std;
int acc[10];
int visited[10];
int N,M;
void f(int cur){
    if(cur==M){
        for(int i=0; i<M; ++i){
            cout << acc[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=N; ++i){
        if(visited[i]) continue;
        visited[i]=1;
        acc[cur]=i;
        f(cur+1);
        visited[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>N>>M;
    f(0);
}
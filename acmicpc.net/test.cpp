#include <bits/stdc++.h>
using namespace std;
int L;
int visited[100];
void f(int n){
    if(n==L+1){
        int res[100]={};
        for(int i=1; i<=L; ++i){
            res[visited[i]] = i;
        }
        for(int i=1; i<=L; ++i){
            cout << res[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=L; ++i){
        if(visited[i]) continue;
        visited[i]=n;
        f(n+1);
        visited[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>L;
    f(1);
}
#include <bits/stdc++.h>
using namespace std;
int arr[12][12];
int visited[12];
int res=0;
void f(int phase, int acc){
    if(phase==11){
        res=max(res,acc);
        return;
    }
    for(int i=0; i<11; ++i){
        if(visited[i]) continue;
        if(arr[phase][i]==0) continue;
        visited[i]=1;
        f(phase+1, acc+arr[phase][i]);
        visited[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        res=0;
        for(int i=0; i<11; ++i){
            for(int j=0; j<11; ++j){
                cin>>arr[i][j];
            }
        }
        f(0, 0);
        cout << res << '\n';
    }
}
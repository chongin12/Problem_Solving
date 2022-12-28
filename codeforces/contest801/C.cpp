#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int res=0;
int N,M;
void init(){
    res=0;
}
void dfs(int i, int j, int cnt) {
    if(res) return;
    if(cnt>(N+M-1)/2 || cnt< -((N+M-1)/2)) return;
    if(i==N-1 && j==M-1){
        if(cnt+arr[i][j]==0) res=1;
        return;
    }
    if(i!=N-1) dfs(i+1,j,cnt+arr[i][j]);
    if(j!=M-1) dfs(i,j+1,cnt+arr[i][j]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        init();
        cin>>N>>M;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                cin>>arr[i][j];
            }
        }
        if(N%2==M%2) {
            cout << "NO\n";
        }
        else{
            dfs(0,0,0);
            if(res) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
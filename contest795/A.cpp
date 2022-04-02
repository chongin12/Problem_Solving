#include <bits/stdc++.h>
using namespace std;
int arr[11];
int N;
int res=987654321;
int dc[11][11]; // dc[i][j] : i번째 물약을 샀을 때 j번째 물약의 할인 정보
void dfs(int x, int cnt, int left, bool bought[11]){
    if(left==0) res=min(res,cnt);
    for(int i=0; i<N; ++i){
        if(!bought[i]){
            //지금 i번째 물약을 살 것.
            int cur=arr[i];
            for(int j=0; j<N; ++j){
                if(bought[j]) cur-=dc[j][i];
            }
            cur=max(cur,1);
            bought[i]=true;
            dfs(i, cnt+cur, left-1, bought);
            bought[i]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        for(int j=0; j<a; ++j){
            int b,c; cin>>b>>c;
            dc[i][b-1]=c;
        }
    }
    bool temp[11]={};
    dfs(-1, 0, N, temp);
    cout << res << '\n';
}
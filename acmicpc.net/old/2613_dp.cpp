#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
vector<int> v;
int N, M; 
int dp[301][301]; // dp[i][j] : 0 ~ i번째 구슬까지 봤을 때 그룹 j개로 쪼개기 => 이 때 최댓값의 최솟값
int psum[301];
int R[301][301]; // 어디서 쪼갰는지.
int query(int a, int b){
    if(a==0) return psum[b];
    return psum[b]-psum[a-1];
}
void f(int k, int m){
    if(m==0) return;
    f(R[k][m], m-1);
    cout << k-R[k][m] << " ";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=0,a; i<N; ++i){
        cin>>a; v.push_back(a);
        if(i==0) psum[0]=a;
        else psum[i]=psum[i-1]+a;
    }
    
    for(int i=0; i<N; ++i){
        dp[i][1]=query(0,i);
        R[i][1]=-1;
        for(int j=2; j<=min(i+1,M); ++j){
            // dp[i][j] 채우기 : j-2번째 구슬부터 i-1번째 구슬까지 그룹 j-1개로 쪼갠 것들과 비교.
            dp[i][j]=INF;
            for(int k=j-2; k<i; ++k){
                if(max(dp[k][j-1], query(k+1, i)) < dp[i][j]){
                    dp[i][j]=max(dp[k][j-1], query(k+1, i));
                    R[i][j] = k;
                }
            }
        }
    }
    cout << dp[N-1][M] << '\n';
    int temp=N-1;
    f(N-1, M);
    cout << '\n';
    return 0;
}
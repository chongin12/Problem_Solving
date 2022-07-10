#include <bits/stdc++.h>
using namespace std;
int psum[4001];
int psum2[4001];
double dp[4001][31];
const double INF=987654321.0;
int sum(int a, int b){
    if(a==0) return psum[b];
    return psum[b]-psum[a-1];
}
int sum2(int a, int b){
    if(a==0) return psum2[b];
    return psum2[b]-psum2[a-1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int B; cin>>B;
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(i==0) {
            psum[i]=a;
            psum2[i]=a*a;
        }
        else {
            psum[i]=psum[i-1]+a;
            psum2[i]=psum2[i-1]+a*a;
        }
    }
    for(int i=0; i<=N; ++i){
        for(int j=0; j<=B; ++j){
            dp[i][j]=INF;
        }
    }
    dp[0][1]=0;
    for(int i=1; i<N; ++i){
        for(int j=0; j<=i; ++j){ // i번째 원소부터 j+1개, i-j ~ i
            double v=sum(i-j,i)/(double)(j+1);
            double r=sum2(i-j,i)-2*v*sum(i-j,i)+(j+1)*v*v; // i-j ~ i까지 편차
            if(j==i){
                dp[i][1]=min(dp[i][1], r);
                continue;
            }
            for(int k=1; k<B && k<=i-j; ++k){ // 묶은거 이전에 그룹이 k개만큼 있었을 때
                dp[i][k+1]=min(dp[i][k+1],dp[i-j-1][k]+r);
            }
        }
    }
    double res=dp[N-1][1];
    for(int i=2; i<=B; ++i){
        res=min(res, dp[N-1][i]);
    }
    cout << fixed;
    cout.precision(6);
    cout << res << '\n';
}
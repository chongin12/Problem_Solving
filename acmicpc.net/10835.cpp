#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001]; // dp[i][j] : j를 매칭한다고 할 때 왼쪽 더미가 i까지, 오른쪽 더미가 j까지있을 때 최댓값
vector<int> v1, v2;
int N;
void init(){
    memset(dp, -1, sizeof dp);
}
int f(int i, int j){
    // f(i,j) : 가장 위에 있는 인덱스가 각각 i, j일 때
    if(dp[i][j]!=-1) return dp[i][j];
    if(i>=N || j>=N) return 0;
    if(v1[i]>v2[j]){
        return dp[i][j]=max({f(i+1, j+1), f(i+1, j), f(i, j+1)+v2[j]});
    }
    return dp[i][j]=max(f(i+1, j+1), f(i+1, j));
}
int main(){
    init();
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v1.push_back(a);
    }
    for(int i=0; i<N; ++i){
        int a; cin>>a; v2.push_back(a);
    }
    cout << f(0,0) << '\n';
}

/*
왼쪽 더미의 큰 점수 하나로 오른쪽 점수를 많이 먹을 수 있음.
왼쪽 더미의 카드는 언제든지 버릴 수 있음.
오른쪽 더미의 큰 점수는 왼쪽 더미 카드 하나와 같이 버릴 수 있음.

오른쪽 더미의 카드를 하나 볼 때 왼쪽 더미의 카드와 하나씩 매칭해본다.
매칭되지 않았을 때도 체크해본다. 나와 같이 버릴 카드를 하나씩 매칭해본다.
매칭이 되면 dp[i][j-1]이랑 합치고, 매칭이 안되면 dp[i-1][j-1]이랑 합친다.

*/
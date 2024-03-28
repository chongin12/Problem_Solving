#include <bits/stdc++.h>
using namespace std;
int dp[11][10];
vector<int> res;
void f(int x, int y, int cnt){
    res.push_back(y);
    if(x==1) return;
    x-=1;
    int temp=0;
    for(int i=0; i<y; ++i){
        temp+=dp[x][i];
        if(temp>=cnt){
            f(x, i, cnt-(temp-dp[x][i]));
            return;
        }
    }
}
int main(){
    int N; cin>>N; N++;
    for(int i=0; i<10; ++i){
        dp[1][i]=1;
    }
    for(int i=2; i<=10; ++i){
        for(int j=1; j<10; ++j){
            for(int k=0; k<j; ++k){
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
    int cnt=0;
    for(int i=1; i<=10; ++i){
        for(int j=0; j<10; ++j){
            cnt+=dp[i][j];
            if(cnt>=N){
                f(i, j, N-(cnt-dp[i][j]));
                for(auto it:res) cout << it;
                cout << '\n';
                return 0;
            }
        }
    }
    cout << "-1\n";
}
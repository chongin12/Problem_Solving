#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[7]; //[0]=월요일
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    dp[v[0]%7]=1;
    for(int i=1; i<N; ++i){
        set<int> temp;
        for(int j=0; j<7; ++j){
            if(dp[j]) temp.insert((j+v[i])%7);
        }
        for(auto it:temp) dp[it]=1;
        dp[v[i]%7]=1;
    }
    if(dp[4]) cout << "YES\n";
    else cout << "NO\n";
}
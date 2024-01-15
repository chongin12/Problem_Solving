#include <bits/stdc++.h>
using namespace std;
vector<string> v;
string s;
int res=0;
int dp[101];
int f(int loc) {
    if(dp[loc]!=-1) return dp[loc];
    for(auto it:v){
        for(int i=0; i<it.size(); ++i){
            if(loc+i>=s.size()) break;
            if(s[loc+i]!=it[i]) break;
            if(i==it.size()-1) {
                if(f(loc+it.size())) return dp[loc]=1;
            }
        }
    }
    return dp[loc]=0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<101; ++i) dp[i]=-1;
    cin>>s;
    dp[s.size()]=1;
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        string a; cin>>a; v.push_back(a);
    }
    
    cout << f(0) << '\n';
}
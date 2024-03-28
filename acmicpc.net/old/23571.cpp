#include <bits/stdc++.h>
using namespace std;
vector<int> goods;
vector<int> tags;
int dp[1000010][4];
int R[1000010][4]; // 역추적
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        int a; cin>>a;
        goods.push_back(a);
    }
    for(int i=0; i<n; ++i){
        int a; cin>>a;
        tags.push_back(a);
    }
    sort(goods.begin(), goods.end());
    sort(tags.begin(), tags.end());
    dp[0][0]=abs(goods[0]-tags[0]);
    dp[0][1]=0;
    if(tags.size()>1) dp[0][2]=abs(goods[0]-tags[1]);
    else dp[0][2]=0;
    dp[0][3]=0;
    for(int i=1; i<n; ++i){
        if(dp[i-1][3]){
            dp[i][3]=max(dp[i-1][3],abs(goods[i]-tags[i]));
        }
        dp[i][0]=max(dp[i-1][0],abs(goods[i]-tags[i]));
        dp[i][1]=max(dp[i-1][1],dp[i-2][0])+abs(goods[i]-tags[i-1]);
        
    }
}
#include <bits/stdc++.h>
using namespace std;
const int MN = 100001;
int isErased[MN];
int dp[MN];
vector<int> res;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2; i*i<MN; ++i){
        for(int j=i*i; j<MN; j+=i){
            isErased[j]=1;
        }
    }
    for(int i=0; i<100; ++i){
        if(!isErased[i]) dp[i]=1;
    }
    int temp=-1;
    for(int i=100; i<MN; ++i){
        string str=to_string(i);
        string str1=str, str2=str;
        str1.pop_back();
        str2.erase(str2.begin());
        int s1=stoi(str1);
        int s2=stoi(str2);
        if(dp[s1] && dp[s2] && !isErased[s1] && !isErased[s2]){
            dp[i]=1;
            if(isErased[i]) res.push_back(i);
        }
    }
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        if(N>=31373) {
            cout << "31373\n";
            continue;
        }
        auto it = upper_bound(res.begin(), res.end(), N) - res.begin() - 1;
        if(it==-1) cout << "-1\n";
        else cout << res[it] << '\n';
    }
}
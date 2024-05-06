#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<int> G[10001];
int isErased[10001];
vector<int> primes;
int visited[10001];
void init(){
    memset(visited, 0, sizeof visited);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int i=2; i*i<=10000; ++i){
        if(isErased[i]) continue;
        for(int j=i*i; j<=10000; j+=i){
            isErased[j]=1;
        }
    }
    for(int i=1000; i<10000; ++i) if(!isErased[i]) primes.push_back(i);
    for(int i=0; i<primes.size(); ++i){
        for(int j=i+1; j<primes.size(); ++j){
            int cnt=0;
            string a=to_string(primes[i]), b=to_string(primes[j]);
            for(int k=0; k<4; ++k) if(a[k]==b[k]) cnt++;
            if(cnt==3) {
                G[primes[i]].push_back(primes[j]);
                G[primes[j]].push_back(primes[i]);
            }
        }
    }
    while(T--){
        init();
        int a, b; cin>>a>>b;
        queue<pii> q;
        q.push({a,0});
        visited[a]=1;
        int res=-1;
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            if(cur.first==b) {
                res = cur.second;
                break;
            }
            for(auto it:G[cur.first]){
                if(!visited[it]){
                    q.push({it, cur.second + 1});
                    visited[it]=1;
                }
            }
        }
        if(res==-1) cout << "Impossible\n";
        else cout << res << '\n';
    }
}
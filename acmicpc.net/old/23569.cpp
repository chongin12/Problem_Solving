#include <bits/stdc++.h>
using namespace std;
int oriG[1010][1010];
vector<int> G[1010]; // 친구가 아닌 간선으로 이루어진 그래프
int p[1010];
int sz[1010];
vector<int> v;
int dp[2][2000001];
void init(){
    for(int i=1; i<1010; ++i){
        p[i]=i;
        sz[i]=1;
    }
}
int Find(int x){
    if(x==p[x]) return x;
    return p[x]=Find(p[x]);
}
void Union(int a, int b){
    int A=Find(a);
    int B=Find(b);
    if(A==B) return;
    // cout << "sz["<<A<<"] : " << sz[A] << '\n';
    // cout << "sz["<<B<<"] : " << sz[B] << '\n';
    sz[A]+=sz[B];
    sz[B]=0;
    p[B]=A;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    int N,M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int u, v; cin>>u>>v;
        oriG[u][v]=1;
        oriG[v][u]=1;
    }
    for(int i=1; i<=N; ++i){
        v.clear();
        for(int j=1; j<=N; ++j){
            if(i==j) continue;
            if(oriG[i][j]==0) {
                // cout << i << " <-> " << j << '\n';
                G[i].push_back(j);
                G[j].push_back(i);
                v.push_back(j);
            }
        }
        for(int j=1; j<v.size(); ++j){
            // cout << "Union : " << v[0] << ", " << v[j] << '\n';
            Union(v[0], v[j]);
        }
    }
    for(int i=1; i<=N; ++i){
        for(auto it:G[i]){
            if(Find(i)==Find(it)){
                cout << "-1\n";
                return 0;
            }
        }
    }
    vector<int> temp;
    int sum=0;
    for(int i=1; i<=N; ++i){
        int k=Find(i);
        if(sz[k]==0) continue;
        int a=sz[k];
        sz[k]=0;
        int b=0;
        if(G[k].size()) {
            b=sz[Find(G[k][0])];
            sz[Find(G[k][0])]=0;
        }
        // cout << "a : " << a << ", b : " << b << '\n';
        if(a==b) continue;
        temp.push_back(abs(a-b));
        sum+=temp.back();
    }
    int goal=sum/2;
    for(int i=0; i<temp.size(); ++i){
        // cout << "temp["<<i<<"]="<<temp[i]<<'\n';
        for(int j=0; j<temp[i]; ++j){
            dp[(i+1)%2][j]=dp[i%2][j];
        }
        for(int j=temp[i]; j<=goal; ++j){
            dp[(i+1)%2][j]=max(dp[i%2][j],dp[i%2][j-temp[i]]+temp[i]);
        }
        
    }
    cout << abs((sum-dp[temp.size()%2][goal])-dp[temp.size()%2][goal]) << '\n';
}
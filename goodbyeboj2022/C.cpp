#include <bits/stdc++.h>
using namespace std;
vector<int> G[3001];
int o1[3001], o2[3001], o3[3001];
int In[3001];
int nxt[3001];
vector<int> v1,v2,v3;
int visited[3001];
vector<int> res;
void f(int x){
    visited[x]=1;
    for(auto it:G[x]){
        if(visited[it]) continue;
        f(it);
    }
    res.push_back(x);
}
int main(){
    int N; cin>>N;
    for(int j=0; j<N; ++j){
        int a; cin>>a;
        v1.push_back(a);
        o1[a]=j;
    }
    for(int j=0; j<N; ++j){
        int a; cin>>a;
        v2.push_back(a);
        o2[a]=j;
    }
    for(int j=0; j<N; ++j){
        int a; cin>>a;
        v3.push_back(a);
        o3[a]=j;
    }
    for(int i=1; i<N; ++i){
        // v1[i-1] -> v1[i] ?
        int a=v1[i-1], b=v1[i];
        if(o2[a]<o2[b] || o3[a]<o3[b]){
            G[a].push_back(b);
            In[b]++;
        }
        else{
            G[b].push_back(a);
            In[a]++;
        }
    }
    for(int i=1; i<N; ++i){
        int a=v2[i-1], b=v2[i];
        if(o1[a]<o1[b] || o3[a]<o3[b]){
            G[a].push_back(b);
            In[b]++;
        }
        else{
            G[b].push_back(a);
            In[a]++;
        }
    }
    for(int i=1; i<N; ++i){
        int a=v3[i-1], b=v3[i];
        if(o1[a]<o1[b] || o2[a]<o2[b]){
            G[a].push_back(b);
            In[b]++;
        }
        else{
            G[b].push_back(a);
            In[a]++;
        }
    }
    for(int i=1; i<=N; ++i){
        if(In[i]==0) G[0].push_back(i);
    }
    f(0);
    res.pop_back();
    reverse(res.begin(), res.end());
    for(auto it:res) cout << it << " ";
    cout << '\n';
}
#include <bits/stdc++.h>
using namespace std;
int arr[101];
int visited[101];
vector<int> res;
void init() {
    for(int i=0; i<101; ++i){
        if(visited[i]!=2) visited[i]=0;
    }
}
void dfs(int x){
    visited[x]=1;
    if(visited[arr[x]]==1){
        //arr[x]부터 x까지 사이클이 생김.
        int a=arr[x];
        while(a!=x){
            res.push_back(a);
            visited[a]=2;
            a=arr[a];
        }
        res.push_back(a);
        visited[a]=2;
        return;
    }
    if(visited[arr[x]]==0) dfs(arr[x]);
}
int main(){
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
    }
    for(int i=1; i<=N; ++i){
        if(visited[i]==2) continue;
        init();
        dfs(i);
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for(auto it:res){
        cout << it << '\n';
    }
}
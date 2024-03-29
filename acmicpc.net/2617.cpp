#include <bits/stdc++.h>
using namespace std;
vector<int> big[100], small[100];
int visited[100];
int calBig(int x){ // x보다 큰 것들의 개수
    int ret=1;
    visited[x]=1;
    for(auto it:big[x]){
        if(visited[it]) continue;
        ret+=calBig(it);
    }
    return ret;
}
int calSmall(int x){ // x보다 작은 것들의 개수
    int ret=1;
    visited[x]=1;
    for(auto it:small[x]){
        if(visited[it]) continue;
        ret+=calSmall(it);
    }
    return ret;
}
int main(){
    int N, M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int a,b; cin>>a>>b;
        big[b].push_back(a);
        small[a].push_back(b);
    }
    int res=0;
    for(int i=1; i<=N; ++i){
        // memset(visited, 0, sizeof visited);
        // cout << "calSmall("<<i<<")="<<calSmall(i)<<'\n';
        // memset(visited, 0, sizeof visited);
        // cout << "calBig("<<i<<")="<<calBig(i)<<'\n';
        memset(visited, 0, sizeof visited);
        if(calSmall(i)-1 >= (N+1)/2){
            continue;
        }
        memset(visited, 0, sizeof visited);
        if(calBig(i)-1 >= (N+2)/2){
            continue;
        }
        res++;
    }
    
    cout << N-res << '\n';
}
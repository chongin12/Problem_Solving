#include <bits/stdc++.h>
using namespace std;
vector<int> G[333334];
queue<int> cha1; // 차수가 1인 노드들 모음
int cha[333334];
int p[333334];
int sz[333334];
int Find(int x){
    if(p[x]==x) return x;
    return p[x]=Find(p[x]);
}
int Union(int a, int b){
    int A=Find(a);
    int B=Find(b);
    if(A<B){
        sz[A]+=sz[B];
        p[B]=A;
        return sz[A];
    }
    else{
        sz[B]+=sz[A];
        p[A]=B;
        return sz[B];
    }
}
void init(){
    for(int i=0; i<333334; ++i){
        p[i]=i;
        sz[i]=1;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        int a,b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        cha[a]++;
        cha[b]++;
    }
    for(int i=1; i<=N; ++i){
        if(cha[i]==1) cha1.push(i);
    }
    while(!cha1.empty()){
        int cur=cha1.back();
        cha1.pop();
    }
}
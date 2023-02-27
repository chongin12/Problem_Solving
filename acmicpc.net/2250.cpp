#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
pair<int,int> G[10001];
pair<int,int> arr[10001]; // {왼쪽끝, 오른쪽끝}
int cannotRoot[10001];
int cnt=1;
void init(){
    for(int i=0; i<10001; ++i) arr[i]={0,0};
    cnt=1;
}
void f(int u, int depth){
    if(G[u].x!=-1){
        f(G[u].x, depth+1);
    }
    if(arr[depth].x==0) arr[depth].x=cnt;
    else arr[depth].y=cnt;
    cnt++;
    if(G[u].y!=-1){
        f(G[u].y, depth+1);
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a, b, c; cin>>a>>b>>c;
        G[a] = {b,c};
        if(b!=-1) cannotRoot[b]=1;
        if(c!=-1) cannotRoot[c]=1;
    }
    pair<int,int> res(1,1); // {레벨, 너비}
    for(int root=1; root<=N; ++root){
        if(cannotRoot[root]) continue;
        init();
        f(root, 1);
        for(int i=1; i<=N; ++i){
            if(arr[i].x==0) continue;
            if(arr[i].x!=0 && arr[i].y==0) arr[i].y=arr[i].x;
            if(arr[i].y-arr[i].x+1>res.y){
                res={i,arr[i].y-arr[i].x+1};
            }
        }
    }
    cout << res.x << " " << res.y << '\n';
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll arr[201][201];
ll W, H;
ll K;
ll hdx[]={-2,-1,1,2,2,1,-1,-2};
ll hdy[]={1,2,2,1,-1,-2,-2,-1};
ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
const ll INF = 987654321;
struct node {
    int x, y, k, acc;
    node(int x, int y, int k, int acc):x(x),y(y),k(k),acc(acc){}
};
int visited[201][201][31];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>K;
    cin>>W>>H;
    for(ll i=0; i<H; ++i){
        for(ll j=0; j<W; ++j){
            cin>>arr[i][j];
        }
    }
    queue<node> q;
    q.push(node(0,0,0,0));
    visited[0][0][0]=1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int i=cur.x, j=cur.y, k=cur.k;
        if(i==H-1 && j==W-1){
            cout << cur.acc << '\n';
            return 0;
        }
        if(cur.k<K){
            for(ll w=0; w<8; ++w){
                ll ni=i+hdx[w];
                ll nj=j+hdy[w];
                if(ni>=0 && ni<H && nj>=0 && nj<W && arr[ni][nj]==0 && visited[ni][nj][k+1]==0){
                    q.push(node(ni, nj, k+1, cur.acc+1));
                    visited[ni][nj][k+1]=1;
                }
            }
        }
        for(ll w=0; w<4; ++w){
            ll ni=i+dx[w];
            ll nj=j+dy[w];
            if(ni>=0 && ni<H && nj>=0 && nj<W && arr[ni][nj]==0 && visited[ni][nj][k]==0){
                q.push(node(ni, nj, k, cur.acc+1));
                visited[ni][nj][k]=1;
            }
        }
    }
    cout << "-1\n";
}